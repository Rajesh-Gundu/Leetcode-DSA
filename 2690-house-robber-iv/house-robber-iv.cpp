class Solution {
public:
    bool isValid(vector<int>& nums, int k,int cap) {
        int h = 0;
        int n = nums.size();
        for(int i=0;i<n;i++) {
            if(nums[i] <= cap) {
                h++;
                i++;
            }
        }
        return h >= k;
    }

    int minCapability(vector<int>& nums, int k) {
        int lo = *min_element(nums.begin(),nums.end());
        int hi = *max_element(nums.begin(),nums.end());
        int ans = 0;
        while(lo <= hi) {
            int mid = lo + (hi-lo)/2;
            if(isValid(nums,k,mid)) {
                ans = mid;
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};
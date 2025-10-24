class Solution {
    int getIdx(vector<int>& lis,int num) {
        int lo = 0;
        int hi = lis.size()-1;
        while(lo <= hi) {
            int mid = lo + (hi-lo)/2;
            if(lis[mid] < num) {
                lo = mid + 1;
            }
            else
                hi = mid - 1;
        } 
        return lo;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis;
        for(int i=0;i<n;i++) {
            if(i == 0 || lis.back() < nums[i])
                lis.push_back(nums[i]);
            else {
                int idx = getIdx(lis,nums[i]);
                lis[idx] = nums[i];
            }

        }
        return lis.size();
    }
};
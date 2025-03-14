class Solution {
public:
    int getFirstPosIdx(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size()-1;
        int idx = nums.size();
        while(lo <= hi) {
            int mid = lo + (hi -lo)/2;
            if(nums[mid] < 0) {
                lo = mid + 1;
            }
            else {
                idx = mid;
                hi = mid - 1;
            }
        }
        return idx;
    }

    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int pos = getFirstPosIdx(nums);
        int neg = pos - 1;
        vector<int> ans;
        while (pos < n && neg >=0) {
            if(nums[pos] < abs(nums[neg])) {
                ans.push_back(nums[pos]*nums[pos]);
                pos++;
            }
            else {
                ans.push_back(nums[neg]*nums[neg]);
                neg--;
            }
        }
        while(pos < n) {
            ans.push_back(nums[pos]*nums[pos]);
            pos++;
        }
        while(neg >= 0) {
            ans.push_back(nums[neg]*nums[neg]);
            neg--;
        }
        return ans;
    }
};
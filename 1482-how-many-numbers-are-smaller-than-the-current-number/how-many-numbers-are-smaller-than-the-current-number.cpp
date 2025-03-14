class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(101,0);
        for(int& num : nums) {
            cnt[num]++;
        }
        for(int i=1;i<101;i++) {
            cnt[i] += cnt[i-1];
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++) {
            if(nums[i] == 0)
                ans[i] = 0;
            else
                ans[i] = cnt[nums[i]-1];
        }
        return ans;
    }
};
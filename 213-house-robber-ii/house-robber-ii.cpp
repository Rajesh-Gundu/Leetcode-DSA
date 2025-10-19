class Solution {
    int memoi(int n,vector<int>& nums,vector<int>& dp) {
        if(n < 0)   return 0;
        if(n == 0)  return nums[0];
        if(dp[n] != -1) return dp[n];
        int include = nums[n] + memoi(n-2,nums,dp);
        int skip = memoi(n-1,nums,dp);
        return dp[n] = max(include,skip);
    }

    int tabulation(int n,vector<int>& nums) {
        if(n == 1)
            return nums[0];
        int prev2 = nums[0];
        int prev1 = max(nums[0],nums[1]);
        for(int i=2;i<n;i++) {
            int include = nums[i] + prev2;
            int skip = prev1;
            int cur = max(include,skip);
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        int s1 = tabulation(n-1,nums);
        nums[0] = 0;
        int s2 = tabulation(n,nums);
        return max(s1,s2);
    }
};
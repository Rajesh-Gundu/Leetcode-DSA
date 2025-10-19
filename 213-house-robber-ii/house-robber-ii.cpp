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
        vector<int> dp(n,-1);
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i=2;i<n;i++) {
            int include = nums[i] + dp[i-2];
            int skip = dp[i-1];
            dp[i] = max(include,skip);
        }
        return dp[n-1];
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
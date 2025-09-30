class Solution {
    int solve(int n,vector<int>& dp) {
        if(dp[n] != -1)
            return dp[n];

        return dp[n] = solve(n-1,dp) + solve(n-2,dp);
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        dp[0] = dp[1] = 1;
        solve(n,dp);
        return dp[n];
    }
};
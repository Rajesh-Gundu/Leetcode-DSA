class Solution {
    int solve(int i,int j,vector<vector<int>>& dp) {
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1)  return dp[i][j];

        return dp[i][j] = solve(i-1,j,dp) + solve(i,j-1,dp);
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n,-1));
        dp[0][0] = 1;
        solve(m-1,n-1,dp);
        return dp[m-1][n-1];
    }
};
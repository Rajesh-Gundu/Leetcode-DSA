class Solution {
    int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp) {
        if(i < 0 || j < 0)  return 1e8;
        if(dp[i][j] != -1)  return dp[i][j];

        return dp[i][j] = grid[i][j] + min(solve(i-1,j,grid,dp),solve(i,j-1,grid,dp));
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        dp[0][0] = grid[0][0];
        return solve(n-1,m-1,grid,dp);
    }
};
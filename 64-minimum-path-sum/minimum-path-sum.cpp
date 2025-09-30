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
        vector<int> prev(m,-1);
        prev[0] = grid[0][0];
        for(int i=1;i<m;i++) {
            prev[i] = prev[i-1] + grid[0][i];
        }
        for(int i=1;i<n;i++) {
            vector<int> cur(m);
            cur[0] = grid[i][0] + prev[0];
            for(int j=1;j<m;j++) {
                cur[j] = grid[i][j] + min(prev[j],cur[j-1]);
            }
            prev = cur;
        }
        return prev[m-1];
    }
};
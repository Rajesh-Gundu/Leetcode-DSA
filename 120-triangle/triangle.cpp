class Solution {
    int solve(int idx,int row,vector<vector<int>>& triangle,vector<vector<int>>& dp) {
        if(row == triangle.back().size()-1)
            return triangle[row][idx];
        if(dp[row][idx] != -1e7) return dp[row][idx];
        return dp[row][idx] = triangle[row][idx] + min(solve(idx,row+1,triangle,dp),solve(idx+1,row+1,triangle,dp));
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();
        vector<vector<int>> dp(n,vector<int> (m,-1e7));
        return solve(0,0,triangle,dp);
    }
};
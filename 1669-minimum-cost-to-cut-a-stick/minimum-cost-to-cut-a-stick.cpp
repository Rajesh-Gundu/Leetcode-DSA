class Solution {
    int solve(int i,int j,vector<int>& cuts,vector<vector<int>>& dp) {
        if(i > j)   return 0;
        if(dp[i][j] != -1)  return dp[i][j];

        int mini = 1e9;
        for(int k=i;k<=j;k++) {
            int cur = solve(i,k-1,cuts,dp) + solve(k+1,j,cuts,dp) + (cuts[j+1] - cuts[i-1]);
            mini = min(mini,cur);
        }
        return dp[i][j] = mini;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int s = cuts.size();
        vector<vector<int>> dp(s,vector<int> (s,-1));
        return solve(1,s-2,cuts,dp);
    }
};
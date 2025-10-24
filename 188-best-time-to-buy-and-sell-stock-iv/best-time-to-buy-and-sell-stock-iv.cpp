class Solution {
    int solve(int i,int buy,int k,int cap,vector<int>& prices,vector<vector<vector<int>>>& dp) {
        if(i == prices.size() || k == cap) return 0;
        if(dp[i][buy][k] != -1) return dp[i][buy][k];

        if(buy) {
            int include = -prices[i] + solve(i+1,0,k,cap,prices,dp);
            int skip = solve(i+1,1,k,cap,prices,dp);
            return dp[i][buy][k] = max(include,skip);
        }
        else {
            int include = prices[i] + solve(i+1,1,k+1,cap,prices,dp);
            int skip = solve(i+1,0,k,cap,prices,dp);
            return dp[i][buy][k] = max(include,skip);
        }
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int> (k,-1)));
        return solve(0,1,0,k,prices,dp);
    }
};
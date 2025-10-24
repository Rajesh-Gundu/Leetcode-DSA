class Solution {
    int solve(int idx,int buy,vector<int>& prices,vector<vector<int>>& dp) {
        if(idx == prices.size())    return 0;
        if(dp[idx][buy] != -1)  return dp[idx][buy];

        if(buy) {
            int include = -prices[idx] + solve(idx+1,0,prices,dp);
            int skip = solve(idx+1,1,prices,dp);
            return dp[idx][buy] = max(include,skip);
        }
        else {
            int include = prices[idx] + solve(idx+1,1,prices,dp);
            int skip = solve(idx+1,0,prices,dp);
            return dp[idx][buy] = max(include,skip);
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,1,prices,dp);
    }
};
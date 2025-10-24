class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2,vector<int> (2,0));

        for(int i=n-1;i>=0;i--) {
            int include = prices[i] + dp[i+2][1];
            int skip = dp[i+1][0];
            dp[i][0] = max(include,skip);

            include = -prices[i] + dp[i+1][0];
            skip = dp[i+1][1];
            dp[i][1] = max(include,skip);
        }

        return dp[0][1];
    }
};
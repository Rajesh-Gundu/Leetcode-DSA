class Solution {
    int memoi(vector<int>& coins, int amount,vector<int>& dp) {
        if(amount < 0)  return 1e7;
        if(amount == 0) return dp[amount] = 0;
        if(dp[amount] != -1)    return dp[amount];

        int res = INT_MAX;
        for(auto& c : coins) {
            int take = memoi(coins,amount-c,dp);
            if(take >= 0)
                res = min(res,take+1);
        }

        if(res >= 1e7)
            return dp[amount] = -2;
        return dp[amount] = res;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        memoi(coins,amount,dp);
        if(dp[amount] == -2)
            return -1;
        return dp[amount];
    }
};
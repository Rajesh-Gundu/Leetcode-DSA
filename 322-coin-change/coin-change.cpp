class Solution {
    int solve(int idx,int amount,vector<int>& coins,vector<vector<int>>& dp) {
        if(idx == 0) {
            if(amount%coins[idx] == 0)  return amount/coins[idx];
            return 1e9;
        }

        if(dp[idx][amount] != -1)   return dp[idx][amount];

        int take = 1e9;
        if(amount >= coins[idx])
            take = 1 + solve(idx,amount-coins[idx],coins,dp);
        int skip = solve(idx-1,amount,coins,dp);
        return dp[idx][amount] = min(take,skip);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        int res = solve(n-1,amount,coins,dp);
        if(res >= 1e9)
            return -1;
        return res;
    }
};
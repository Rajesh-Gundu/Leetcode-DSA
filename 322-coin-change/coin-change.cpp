class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        dp[0] = 0;
        for(int i=1;i<=amount;i++) {
            int res = 1e7;
            for(int& c : coins) {
                if(c <= i) {
                    res = min(res,1+dp[i-c]);
                }
            }
            dp[i] = res;
        }
        if(dp[amount] >= 1e7)
            return -1;
        return dp[amount];
    }
};
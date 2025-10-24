class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int nextNotBuy = 0;
        int nextBuy = 0;
        int curNotBuy, curBuy;
        
        for(int i=n-1;i>=0;i--) {
            curNotBuy = max(prices[i] + nextBuy,nextNotBuy);
            curBuy = max(-prices[i] + nextNotBuy,nextBuy);

            nextBuy = curBuy;
            nextNotBuy = curNotBuy;
        }

        return nextBuy;
    }
};
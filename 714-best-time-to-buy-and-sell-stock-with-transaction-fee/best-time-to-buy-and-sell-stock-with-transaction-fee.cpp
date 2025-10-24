class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int nextBuy = 0, nextNotBuy = 0, curBuy = 0, curNotBuy = 0;

        for(int i=n-1;i>=0;i--) {
            curBuy = max(-prices[i]+nextNotBuy,nextBuy);
            curNotBuy = max(prices[i]-fee + nextBuy, nextNotBuy);

            nextBuy = curBuy;
            nextNotBuy = curNotBuy;
        } 
        return nextBuy;
    }
};
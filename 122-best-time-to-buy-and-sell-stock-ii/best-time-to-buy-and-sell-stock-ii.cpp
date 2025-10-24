class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> next(2,0);
        
        for(int i=n-1;i>=0;i--) {
            vector<int> cur(2,0);
            
            int include = prices[i] + next[1];
            int skip = next[0];
            cur[0] = max(include,skip);

            include = -prices[i] + next[0];
            skip = next[1];
            cur[1] = max(include,skip);
            
            next = cur;
        }

        return next[1];
    }
};
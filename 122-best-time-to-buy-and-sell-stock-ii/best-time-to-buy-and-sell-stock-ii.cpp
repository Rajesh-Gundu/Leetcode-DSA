class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> next(2,0);
        
        for(int i=n-1;i>=0;i--) {
            vector<int> cur(2,0);
            for(int j=0;j<2;j++) {
                if(j == 0) {
                    int include = prices[i] + next[1];
                    int skip = next[0];
                    cur[j] = max(include,skip);
                }
                else {
                    int include = -prices[i] + next[0];
                    int skip = next[1];
                    cur[j] = max(include,skip);
                }
            }
            next = cur;
        }

        return next[1];
    }
};
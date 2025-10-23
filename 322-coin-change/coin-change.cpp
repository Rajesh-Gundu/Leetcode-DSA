class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount+1,1e9);
        
        for(int i=0;i<=amount;i++) {
            if(i%coins[0] == 0) 
                prev[i] = i/coins[0];
        }

        for(int i = 1;i<n;i++) {
            vector<int> cur(amount+1);
            for(int j=0;j<=amount;j++) {
                int take = 1e9;
                if(j >= coins[i])
                    take = 1 + cur[j-coins[i]];
                int skip = prev[j];
                cur[j] = min(take,skip);
            }
            prev = cur;
        }


        if(prev[amount] >= 1e9)
            return -1;
        return prev[amount];
    }
};
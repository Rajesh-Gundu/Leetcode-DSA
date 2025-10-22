class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        queue<pair<int,int>> q;
        q.push({0,amount});
        vector<bool> vis(amount+1,false); 
        vis[amount] = true;
        while(!q.empty()) {
            int steps = q.front().first;
            int value = q.front().second;
            q.pop();
            if(value == 0)
                return steps;
            for(int& c : coins) {
                if(c <= value && !vis[value-c]) {
                    q.push({steps+1,value-c});
                    vis[value-c] = true;
                }
            }
        }
        return -1;
    }
};
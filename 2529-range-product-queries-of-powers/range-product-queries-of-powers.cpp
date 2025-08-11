class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers(32,0);
        int idx = 0;
        for(int i=0;i<32;i++) {
            if((n>>i) & 1)
                powers[idx++] = (1<<i);
        }
        vector<int> ans;
        int m = 1e9+7;
        for(auto q : queries) {
            int i = q[0];
            int j = q[1];
            long prod = 1;
            while(i <= j) {
                prod = (prod * powers[i])%m;
                i++;
            }
            ans.push_back(prod);
        }
        return ans;
    }
};
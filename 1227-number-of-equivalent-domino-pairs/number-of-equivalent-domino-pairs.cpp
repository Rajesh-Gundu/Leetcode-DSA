class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<vector<int>> mp(10,vector<int> (10,0));
        for(auto& d : dominoes){
            if(d[0] < d[1]) {
                mp[d[0]][d[1]]++;
            }
            else {
                mp[d[1]][d[0]]++;
            }
        }
        int ans = 0;
        for(int i=1;i<10;i++) {
            for(int j=i;j<10;j++) {
                int c = mp[i][j];
                ans += ((c-1)*c)/2;
            }
        }
        return ans;
    }
};
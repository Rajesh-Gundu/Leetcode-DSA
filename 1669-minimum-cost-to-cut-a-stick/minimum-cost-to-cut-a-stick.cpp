class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int s = cuts.size();
        vector<vector<int>> dp(s,vector<int> (s,0));
        for(int i=s-2;i>=1;i--) {
            for(int j=i;j<s-1;j++) {
                int mini = 1e9;
                for(int k=i;k<=j;k++) {
                    int cur = dp[i][k-1] + dp[k+1][j] + (cuts[j+1]-cuts[i-1]);
                    mini = min(mini,cur);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][s-2];
    }
};
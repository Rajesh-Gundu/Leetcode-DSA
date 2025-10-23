class Solution {
    int solve(int i,int j,string& s, string& t,vector<vector<int>>& dp) {
        if(j < 0)   return 1;
        if(i < 0)   return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j]) {
            return dp[i][j] = solve(i-1,j-1,s,t,dp) + solve(i-1,j,s,t,dp);
        }
        return dp[i][j] = solve(i-1,j,s,t,dp);
    }
public:
    int numDistinct(string s, string t) {
        int n1 = s.length();
        int n2 = t.length();
        vector<vector<int>> dp(n1,vector<int> (n2,-1));
        return solve(n1-1,n2-1,s,t,dp);
    }
};
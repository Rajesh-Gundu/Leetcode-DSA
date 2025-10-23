class Solution {
    bool allStars(int i,string& s) {
        while(i >= 0 && s[i] == '*')    i--;
        return i < 0;
    }

    bool solve(int i,int j,string& s1, string& s2,vector<vector<int>>& dp) {
        if(i < 0 && j < 0)  return true;
        if(i < 0)   return false;
        if(j < 0)   return allStars(i,s1);
        if(dp[i][j] != -1)  return dp[i][j];

        if(s1[i] == s2[j] || s1[i] == '?')
            return dp[i][j] = solve(i-1,j-1,s1,s2,dp);
        else if(s1[i] == '*')
            return dp[i][j] = solve(i,j-1,s1,s2,dp) || solve(i-1,j,s1,s2,dp);
        return false;
    }

public:
    bool isMatch(string s2, string s1) {
        int n1 = s1.length();
        int n2 = s2.length();

        vector<vector<int>> dp(n1,vector<int> (n2,-1));

        return solve(n1-1,n2-1,s1,s2,dp);
    }
};
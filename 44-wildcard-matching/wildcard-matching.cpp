class Solution {
    bool allStars(int i,string& s) {
        while(i >= 0 && s[i] == '*')    i--;
        return i < 0;
    }

public:
    bool isMatch(string s2, string s1) {
        int n1 = s1.length();
        int n2 = s2.length();

        vector<vector<int>> dp(n1+1,vector<int> (n2+1,0));
        dp[0][0] = 1;

        for(int i=1;i<=n1;i++) {
            if(allStars(i-1,s1))
                dp[i][0] = 1;
        }

        for(int i=1;i<=n1;i++) {
            for(int j=1;j<=n2;j++) {
                if(s1[i-1] == s2[j-1] || s1[i-1] == '?')
                    dp[i][j] = dp[i-1][j-1];
                else if(s1[i-1] == '*')
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
            }
        }

        return dp[n1][n2];
    }
};
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        if(n == 1)  return 1;
        vector<vector<int>> dp(n,vector<int> (n,0));
        for(int i=0;i<n;i++)
            dp[i][i] = 1;

        for(int i=0;i<n-1;i++) {
            if(s[i] == s[i+1])
                dp[i][i+1] = 2;
            else
                dp[i][i+1] = 1;
        }
        
        for(int k=2;k<n;k++) {
            int i = 0;
            int j = k;
            while(i < n && j < n) {
                if(s[i] == s[j]) {
                    dp[i][j] = 2 + dp[i+1][j-1];
                }
                else
                    dp[i][j] = max(dp[i][j-1],dp[i+1][j]);
                i++;
                j++;
            }
        }

        return dp[0][n-1];
    }
};
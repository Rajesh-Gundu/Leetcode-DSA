class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s1 = s;
        reverse(s1.begin(),s1.end());

        int n = s.length();
        vector<int> prev(n+1,0);

        for(int i=1;i<=n;i++) {
            vector<int> cur(n+1,0);
            for(int j=1;j<=n;j++) {
                if(s[i-1] == s1[j-1])
                    cur[j] = 1 + prev[j-1];
                else
                    cur[j] = max(prev[j],cur[j-1]);
            }
            prev = cur;
        }

        return prev[n];
    }
};
class Solution {
public:
    int numDistinct(string s, string t) {
        int n1 = s.length();
        int n2 = t.length();
        vector<unsigned long long> prev(n2+1,0);
        prev[0] = 1;
        
        for(int i=1;i<=n1;i++) {
            vector<unsigned long long> cur(n2+1,0);
            cur[0] = 1;
            for(int j=1;j<=n2;j++) {
                if(s[i-1] == t[j-1]) {
                    cur[j] = prev[j-1] + prev[j];
                }
                else
                    cur[j] = prev[j];
            }
            prev = cur;
        }

        return prev[n2];
    }
};
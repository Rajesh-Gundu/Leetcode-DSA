class Solution {
public:
    int minInsertions(string s1) {
        string s2 = s1;
        reverse(s2.begin(),s2.end());
        int n = s1.length();
        vector<int> prev(n+1,0);

        for(int i=1;i<=n;i++) {
            vector<int> cur(n+1,0);
            for(int j=1;j<=n;j++) {
                if(s1[i-1] == s2[j-1]) 
                    cur[j] = 1 + prev[j-1];
                else
                    cur[j] = max(prev[j],cur[j-1]);
            }
            prev = cur;
        }

        return n-prev[n];
    }
};
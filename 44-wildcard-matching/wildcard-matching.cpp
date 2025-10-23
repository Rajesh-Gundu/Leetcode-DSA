class Solution {
    bool allStars(int i,string& s) {
        while(i >= 0 && s[i] == '*')    i--;
        return i < 0;
    }

public:
    bool isMatch(string s2, string s1) {
        int n1 = s1.length();
        int n2 = s2.length();

        vector<int> prev(n2+1,0);
        prev[0] = 1;

        for(int i=1;i<=n1;i++) {
            vector<int> cur(n2+1,0);
            if(allStars(i-1,s1))
                cur[0] = 1;
            for(int j=1;j<=n2;j++) {
                if(s1[i-1] == s2[j-1] || s1[i-1] == '?')
                    cur[j] = prev[j-1];
                else if(s1[i-1] == '*')
                    cur[j] = cur[j-1] || prev[j];
            }
            prev = cur;
        }

        return prev[n2];
    }
};
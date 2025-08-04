class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int ans = 1;
        vector<int> firstIdx(26,-1);
        for(int i=0;i<n;i++) {
            if(firstIdx[s[i]-'A'] == -1)
                firstIdx[s[i]-'A'] = i;
        }

        for(int i=0;i<26;i++) {
            if(firstIdx[i] == -1)  continue;

            int l = 0;
            int r = 0;
            char ch = i+65;
            int cnt = k;
            while(r < n) {
                if(ch != s[r]) {
                    if(cnt) {
                        cnt--;
                    }
                    else {
                        while(l < r && s[l] == ch)
                            l++;
                        l++;
                    }
                }
                ans = max(ans,r-l+1);
                r++;
            }
        }
        return ans;
    }
};
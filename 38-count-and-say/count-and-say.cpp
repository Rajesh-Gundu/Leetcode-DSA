class Solution {
public:
    string getRLE(string s) {
        string rle;
        int n = s.length();
        int i = 0;
        while(i < n) {
            char ch = s[i];
            int cnt = 0;
            while(i < n && s[i] == ch) {
                cnt++;
                i++;
            }
            rle += to_string(cnt);
            rle += ch;
        }
        return rle;
    }
    string countAndSay(int n) {
        string ans = "1";
        n--;
        while(n--) {
            ans = getRLE(ans);
        }
        return ans;
    }
};
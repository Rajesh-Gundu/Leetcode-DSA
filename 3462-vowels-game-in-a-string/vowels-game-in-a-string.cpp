class Solution {
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
public:
    bool doesAliceWin(string s) {
        int cnt = 0;
        for(char ch : s) {
            if(isVowel(ch))
                cnt++;
        }
        return cnt > 0;
    }
};
class Solution {
public:
    bool checkValidString(string s) {
        int openCnt = 0;
        int closeCnt = 0;
        int n = s.length();
        for(int i=0;i<n;i++) {
            if(s[i] == '(' || s[i] == '*')
                openCnt++;
            else
                openCnt--;

            if(s[n-i-1] == ')' || s[n-i-1] == '*')
                closeCnt++;
            else
                closeCnt--;

            if(openCnt < 0 || closeCnt < 0)
                return false;
        }
        return true;
    }
};
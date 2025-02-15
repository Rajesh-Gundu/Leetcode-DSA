class Solution {
public:
    bool check(int num,string& s,int idx,int cur) {
        if(idx == s.length()) {
            return (cur == num);
        }
        int n = 0;
        for(int i=idx;i<s.length();i++) {
            n = n*10 + (s[i]-'0');
            if(check(num,s,i+1,cur+n))
                return true;
        }
        return false;
    }
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i=1;i<=n;i++) {
            int sq = i*i;
            string s;
            while(sq) {
                int ld = sq%10;
                sq /= 10;
                s += char(ld+48);
            }
            reverse(s.begin(),s.end());
            if(check(i,s,0,0)) {
                ans += (i*i);
            }
        }
        return ans;
    }
};
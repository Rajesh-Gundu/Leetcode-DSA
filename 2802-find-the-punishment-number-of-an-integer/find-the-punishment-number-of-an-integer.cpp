class Solution {
public:
    bool check(int target,string& s,int idx,int prevSum) {
        if(idx == s.length()) {
            return (target == prevSum);
        }
        int cur = 0;
        for(int i=idx;i<s.length();i++) {
            cur = cur*10 + (s[i]-'0');
            if(check(target,s,i+1,prevSum+cur))
                return true;
        }
        return false;
    }
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i=1;i<=n;i++) {
            int sq = i*i;
            string s = to_string(sq);
            if(check(i,s,0,0)) {
                ans += (sq);
            }
        }
        return ans;
    }
};
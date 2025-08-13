class Solution {
public:
    void solve(int o,int c,int n,string cur,vector<string>& ans) {
        if(cur.length() == n) {
            ans.push_back(cur);
            return;
        }
        if(o < n/2) {
            solve(o+1,c,n,cur+"(",ans);
        }
        if(c < o) {
            solve(o,c+1,n,cur+")",ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(0,0,2*n,"",ans);
        return ans;
    }
};
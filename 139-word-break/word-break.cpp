class Solution {
public:
    bool solve(int idx,string& s,unordered_set<string>& dict,vector<int>& dp) {
        if(idx == s.length())
            return true;
        if(dp[idx] != -1)
            return dp[idx];
        string cur = "";
        for(int i=idx;i<s.length();i++) {
            cur += s[i];
            if(dict.count(cur) && solve(i+1,s,dict,dp))
                return dp[idx] = true;
        }
        return dp[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.length(),-1);
        unordered_set<string> dict;
        for(auto w : wordDict) {
            dict.insert(w);
        }
        return solve(0,s,dict,dp);
    }
};
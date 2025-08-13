class Solution {
public:
    void solve(string& digits,int i,string cur,unordered_map<int,string>& mp,vector<string>& ans) {
        if(i >= digits.size()) {
            ans.push_back(cur);
            return;
        }
        for(auto ch : mp[digits[i]-'0']) {
            solve(digits,i+1,cur+ch,mp,ans);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits == "")
            return {};
        unordered_map<int,string> mp;
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        vector<string> ans;
        solve(digits,0,"",mp,ans);
        return ans;
    }
};
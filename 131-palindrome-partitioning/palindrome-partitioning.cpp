class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length()-1;
        while(i < j) {
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(int idx,string s,vector<string> partitions,vector<vector<string>>& ans) {
        if(idx == s.length()) {
            ans.push_back(partitions);
            return;
        }
        string cur = "";
        for(int i=idx;i<s.length();i++) {
            cur += s[i];
            if(isPalindrome(cur)) {
                partitions.push_back(cur);
                solve(i+1,s,partitions,ans);
                partitions.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partitions;
        solve(0,s,partitions,ans);
        return ans;
    }
};
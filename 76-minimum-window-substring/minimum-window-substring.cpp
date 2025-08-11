class Solution {
public:
    bool check(unordered_map<char,int>& mpt,unordered_map<char,int>& mps) {
        for(auto i : mpt) {
            char ch = i.first;
            int freq = i.second;
            if(!mps.count(ch) || mps[ch] < freq)
                return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        unordered_map<char,int> mpt;
        for(char ch : t) {
            mpt[ch]++;
        }

        int i = 0;
        int j = 0;
        int n = s.length();
        string ans = "";
        unordered_map<char,int> mps; 
        while(j < n) {
            mps[s[j]]++;
            while(i < j && (!mpt.count(s[i]) || (mps[s[i]]) > mpt[s[i]])) {
                if(mps[s[i]] > 1)
                    mps[s[i]]--;
                else
                    mps.erase(s[i]);
                i++;
            }
            if(check(mpt,mps)) {
                if(ans == "" || ans.length() > (j-i+1)) {
                    ans = s.substr(i,(j-i+1));
                }
            }
            j++;
        }
        return ans;
    }
};
class Solution {
    bool isPresentOnRight(vector<int>& cnt,vector<int>& cur) {
        for(int i=0;i<26;i++) {
            if(cur[i] > 0 && cnt[i] > 0)
                return false;
        }
        return true;
    }
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        vector<int> cnt(26,0);
        for(auto& ch : s) {
            cnt[ch-'a']++;
        }

        vector<int> ans;
        int i = 0;
        while(i < n) {
            int j = i;
            vector<int> cur(26,0);
            while(j < n) {
                cur[s[j]-'a']++;
                cnt[s[j]-'a']--;
                if(isPresentOnRight(cnt,cur)) {
                    ans.push_back(j-i+1);
                    i = j+1;
                    break;
                }
                else {
                    j++;
                }
            }
        }
        return ans;
    }
};
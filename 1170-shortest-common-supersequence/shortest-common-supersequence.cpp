class Solution {
public:
    int memoi(string& s1, string& s2,int i,int j,vector<vector<int>>& dp) {
        if(i == s1.length() || j == s2.length())
            return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) {
            return dp[i][j] = 1+memoi(s1,s2,i+1,j+1,dp);
        }
        return dp[i][j] = max(memoi(s1,s2,i,j+1,dp),memoi(s1,s2,i+1,j,dp));
    }
    string shortestCommonSupersequence(string& str1, string& str2) {
        int n = str1.length();
        int m = str2.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        memoi(str1,str2,0,0,dp);
        string ans;
        int i = 0;
        int j = 0;
        while(i < n && j < m) {
            if(str1[i] == str2[j]) {
                ans.push_back(str1[i]);
                i++;
                j++;
            }
            else {
                if(j+1 < m && i+1 < n) {
                    if(dp[i+1][j] >= dp[i][j+1]) {
                        ans.push_back(str1[i]);
                        i++;
                    }
                    else {
                        ans.push_back(str2[j]);
                        j++;
                    }
                }
                else if(j+1 >= m && i+1 >= n) {
                    ans.push_back(str1[i]);
                    ans.push_back(str2[j]);
                    i++;
                    j++;
                    break;
                }
                else if(j+1 >= m) {
                    ans.push_back(str1[i]);
                    i++;
                }
                else {
                    ans.push_back(str2[j]);
                    j++;
                }
            }
        }
        while(i < n) {
            ans += str1[i];
            i++;
        }
        while(j < m) {
            ans += str2[j];
            j++;
        }
        return ans;
    }
};
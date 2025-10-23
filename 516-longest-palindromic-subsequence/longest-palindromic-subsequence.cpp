class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        if(n == 1)  return 1;

        vector<int> prev2(n,0);
        for(int i=0;i<n;i++)
            prev2[i] = 1;

        vector<int> prev1(n,0);
        for(int i=0;i<n-1;i++) {
            if(s[i] == s[i+1]) {
                prev1[i] = 2;
            }
            else
                prev1[i] = 1;
        }
        
        for(int k=2;k<n;k++) {
            int i = 0;
            int j = k;
            vector<int> cur(n,0);
            while(i < n && j < n) {
                if(s[i] == s[j]) {
                    cur[i] = 2 + prev2[i+1];
                }
                else
                    cur[i] = max(prev1[i],prev1[i+1]);
                i++;
                j++;
            }

            prev2 = prev1;
            prev1 = cur; 
        }

        return prev1[0];
    }
};
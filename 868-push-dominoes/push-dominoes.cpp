class Solution {
public:
    string pushDominoes(string dominoes) {
        int l = -1;
        int n = dominoes.size();
        int p = 0;
        string ans = dominoes;
        int lastPos = 0;
        while(p < n) {
            if(dominoes[p] == 'R') {
                int l = p;
                while(p < n && dominoes[p] != 'L') {
                    if(dominoes[p] == 'R') {
                        for(int i=l;i<=p;i++) {
                            ans[i] = 'R';
                        }
                        l = p;
                    }
                    p++;
                }
                if(p == n) {
                    for(int i=l;i<n;i++) {
                        ans[i] = 'R';
                    }
                }
                else {
                    int r = p;
                    while(l < r) {
                        ans[l++] = 'R';
                        ans[r--] = 'L';
                    }
                    if(l == r)
                        ans[l] = '.';
                    lastPos = p+1;
                } 
            }
            else if(dominoes[p] == 'L'){
                for(int i=p;i>=lastPos;i--)
                    ans[i] = 'L';
            }
            p++;
        }
        return ans;
    }
};
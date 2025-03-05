class Solution {
public:
    long long coloredCells(int n) {
        long long ans = 1;
        while(n > 1) {
            ans += (n-1)*4;
            n--;
        }
        return ans; 
    }
};
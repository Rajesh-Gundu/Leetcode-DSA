class Solution {
public:
    double myPow(double x, long n) {
        if(n < 0) return 1/(myPow(x,-n));
        
        double res = x;
        double ans = 1;
        while(n) {
            if(n&1) {
                ans *= res;
            }
            res *= res;
            n >>= 1;
        }
        return ans;
    }
};
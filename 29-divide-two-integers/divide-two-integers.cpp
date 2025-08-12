class Solution {
public:
    int divide(long long dividend, long long divisor) {
        if((dividend == INT_MIN || dividend == INT_MAX) && divisor == 1)
            return dividend;
        if(dividend == divisor) return 1;
        bool isPos = (dividend < 0 == divisor < 0);
        dividend = abs(dividend);
        divisor = abs(divisor);
        long long q = 0;
        for(int i=30;i>=0;i--) {
            if((1ll<<i)*divisor <=  dividend) {
                q += (1ll<<i);
                dividend -= ((1ll<<i)*divisor);
            }
        }
        if(isPos)
            return q;
        return -q;
    }
};
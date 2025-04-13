class Solution {
    int computeApowB(long long a,long long b) {
        long long ans = 1;
        int m = 1e9+7;
        long long x = a;
        while(b) {
            if(b&1) {
                ans = (ans*x)%m;
            }
            x = (x*x)%m;
            b >>= 1;
        }
        return ans%m;
    }
public:
    int countGoodNumbers(long long n) {
        int m = 1e9+7;
        long long a = computeApowB(5,(n+1)/2);
        long long b = computeApowB(4,n/2);
        return (a*b)%m;
    }
};
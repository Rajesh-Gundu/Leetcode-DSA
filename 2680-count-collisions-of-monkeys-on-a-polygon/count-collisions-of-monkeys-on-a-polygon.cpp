class Solution {
public:
    long long ApowB(long long A,int B) {
        int m = 1e9+7;
        long long ans = 1;
        while(B >= 1) {
            if(B&1) {
                ans = (ans*A)%m;

            }
            A = (A*A)%m;
            B >>= 1;
        }
        return (int)(ans-2+m)%m;
    }
    int monkeyMove(int n) {
        return ApowB(2,n);
    }
};
class Solution {
public:
    bool checkPowersOfThree(int n) {
        int pos = 0;
        int ans = 0;
        int nn = n;
        while(n) {
            if(n%3)
                ans += pow(3,pos);
            n /= 3;
            pos++;
        }
        return (nn == ans);
    }
};
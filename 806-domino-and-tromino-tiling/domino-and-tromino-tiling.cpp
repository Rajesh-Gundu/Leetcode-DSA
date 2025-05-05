class Solution {
    int memoi(vector<int>& dp,int n) {
        if(n == 0)
            return 1;
        else if(n < 0)
            return 0;
        else if(n <= 2)
            return n;
        else if(dp[n] != -1)
            return dp[n];
        long c2 = memoi(dp,n-1)*2;
        long c3 = memoi(dp,n-3);
        return dp[n] = (c2+c3)%1000000007;
    }
public:
    int numTilings(int n) {
        vector<int> dp(1001,-1);
        return memoi(dp,n);
    }
};
class Solution {
    bool memoi(int i,int cur,int rest,vector<int>& nums,vector<vector<int>>& dp) {
        if(cur == rest) return true;
        if(i < 0 || cur > rest)   return false;
        if(dp[i][cur] != -1)    return dp[i][cur];

        return dp[i][cur] = memoi(i-1,cur+nums[i],rest-nums[i],nums,dp) || memoi(i-1,cur,rest,nums,dp);
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(nums.begin(),nums.end(),0);
        if(total%2) return false;
        vector<vector<int>> dp(n,vector<int> (total/2 + 1,0));
        for(int i=0;i<n;i++) {
            dp[i][0] = 1;
        }

        if(nums[0] <= total/2) {
            dp[0][nums[0]] = 1;
        }
        for(int i=1;i<n;i++) {
            for(int j=1;j<=total/2;j++) {
                if(nums[i] <= j) {
                    dp[i][j] = dp[i-1][j-nums[i]];
                }
                dp[i][j] |= dp[i-1][j];
            }
        }
        return dp[n-1][total/2];
    }
};
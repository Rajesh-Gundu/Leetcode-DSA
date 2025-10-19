class Solution {
    int memoi(int n,vector<int>& nums,vector<int>& dp) {
        if(n < 0)   return 0;
        if(n == 0)  return nums[0];
        if(dp[n] != -1) return dp[n];
        int include = nums[n] + memoi(n-2,nums,dp);
        int skip = memoi(n-1,nums,dp);
        return dp[n] = max(include,skip);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        vector<int> dp(n,-1);
        int s1 = memoi(n-2,nums,dp);
        nums[0] = 0;
        fill(dp.begin(),dp.end(),-1);
        int s2 = memoi(n-1,nums,dp);
        return max(s1,s2);
    }
};
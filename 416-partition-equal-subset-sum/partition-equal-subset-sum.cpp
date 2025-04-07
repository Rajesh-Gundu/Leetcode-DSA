class Solution {
    bool solve(vector<int>& nums,int s1,int s2,int idx,vector<vector<int>>& dp) {
        if(s1 == s2)
            return true;
        if(idx < 0)
            return false;
        if(dp[idx][s2] != -1) return dp[idx][s2];

        return dp[idx][s2] = solve(nums,s1-nums[idx],s2+nums[idx],idx-1,dp) || solve(nums,s1,s2,idx-1,dp);
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>> dp(n,vector<int> (sum+1,-1));
        return solve(nums,sum,0,n-1,dp);
    }
};
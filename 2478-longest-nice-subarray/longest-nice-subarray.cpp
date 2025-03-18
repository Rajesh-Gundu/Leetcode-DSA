class Solution {
public:

    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int s = 0;
        int usedBits = 0;
        int e = 0;
        while(e < n) {
            while((usedBits & nums[e]) != 0) {
                usedBits ^= nums[s];
                s++;
            }
            usedBits |= nums[e];
            ans = max(ans,e-s+1);
            e++;
        }
        return ans;
    }
};
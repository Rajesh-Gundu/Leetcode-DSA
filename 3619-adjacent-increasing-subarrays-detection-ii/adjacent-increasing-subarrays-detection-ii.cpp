class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n);
        vector<int> right(n);
        right[n-1] = 1;
        for(int i=n-2;i>=0;i--) {
            if(nums[i] < nums[i+1]) {
                right[i] = 1 + right[i+1];
            }
            else 
                right[i] = 1;
        }
        left[0] = 1;
        for(int i=1;i<n;i++) {
            if(nums[i] > nums[i-1]) {
                left[i] = 1 + left[i-1];
            }
            else 
                left[i] = 1;
        }

        int ans = 1;
        for(int i=1;i<n;i++) {
            ans = max(ans,min(right[i],left[i-1]));
        }
        return ans;
    }
};
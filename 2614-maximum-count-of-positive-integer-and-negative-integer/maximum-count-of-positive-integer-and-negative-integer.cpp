class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int neg = 0;
        int n = nums.size();
        for(int i=0;i<n;i++) {
            if(nums[i] > 0) {
                return max(neg,n-i);
            }
            else if(nums[i] < 0)
                neg++;
        }
        return neg;
    }
};
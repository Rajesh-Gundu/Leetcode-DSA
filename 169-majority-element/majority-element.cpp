class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 1;
        int idx = 0;
        int n = nums.size();
        for(int i=1;i<n;i++) {
            if(nums[i] != nums[idx])
                cnt--;
            else
                cnt++;
            if(cnt == 0) {
                idx = i;
                cnt = 1;
            }
        }
        return nums[idx];
    }
};
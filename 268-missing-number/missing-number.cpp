class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<=n;i++) {
            bool isFind = false;
            for(int j=0;j<n;j++) {
                if(nums[j] == i) {
                    isFind = true;
                    break;
                }
            }
            if(!isFind)
                return i;
        }
        return 0;
    }
};
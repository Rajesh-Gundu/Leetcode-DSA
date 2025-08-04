class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int n = nums.size();
        int ans = 0;
        int cnt = k;
        while(j < n) {
            if(nums[j] == 0) {
                if(cnt)
                    cnt--;
                else {
                    while(i < j && nums[i] != 0) i++;
                    i++;
                    //cnt = 1;
                }
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
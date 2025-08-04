class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        int i = 0;
        int j = 0;
        while(j < n) {
            bool f = true;
            if(nums[j]%2) {
                if(k) {
                    k--;
                }
                else {
                    f = false;
                }
            }
            if(k == 0) {
                int r = j+1;
                while(r < n && nums[r]%2 == 0)
                    r++;
                while(i <= j && k == 0) {
                    if(nums[i]%2)
                        k++;
                    i++;
                    ans += (r-j);
                }
            }
            if(f)
                j++;
        }
        return ans;
    }
};
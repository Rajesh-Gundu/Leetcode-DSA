class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int ans = 0;
        int i = 0;
        int j = 0;
        bool zero = (goal == 0);
        while(j < n) {
            bool f = true;
            if(nums[j]) {
                if(goal) {
                    goal--;
                }
                else if(!zero)
                    f = false;
            }
            if(goal == 0 && !(zero && nums[j])) {
                int r = j+1;
                while(r < n && nums[r] == 0)
                    r++;
                while(i <= j && goal == 0) {
                    if(nums[i]) {
                        if(zero) {
                            i++;
                            continue;
                        }
                        else
                            goal++;

                    }
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
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        int i = 0;
        int j = 0;
        int prevEvens = 0;
        int odds = 0;
        while(j < n) {
            if(nums[j]%2)
                odds++;
            while(i < j && ((nums[i]%2==0) || (odds > k))) {
                if(nums[i]%2 == 0) {
                    prevEvens++;
                }
                else {
                    prevEvens = 0;
                    odds--;
                }
                i++;
            }
            if(odds == k) {
                ans += 1 + prevEvens;
            }
            j++;
        }
        return ans;
    }
};
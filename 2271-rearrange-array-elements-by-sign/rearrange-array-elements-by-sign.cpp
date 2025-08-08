class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int p1 = 0;
        int p2 = 1;
        vector<int> ans(n);
        for(auto num : nums) {
            if(num > 0) {
                ans[p1] = num;
                p1 += 2;
            }
            else {
                ans[p2] = num;
                p2 += 2;
            }
        }
        return ans;
    }
};
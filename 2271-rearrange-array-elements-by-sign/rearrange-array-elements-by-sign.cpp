class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int p1 = 0;
        int p2 = 0;
        vector<int> ans(n);
        int idx = 0;
        while(true) {
            while(p1 < n && nums[p1] < 0)
                p1++;
            while(p2 < n && nums[p2] > 0)
                p2++;
            if(p1 >= n)
                break;
            ans[idx] = nums[p1];
            ans[idx+1] = nums[p2];
            p1++;
            p2++;
            idx += 2;
        }
        return ans;
    }
};
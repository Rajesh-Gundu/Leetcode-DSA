class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = (1 << nums.size());
        for(int i=0;i<(n);i++) {
            vector<int> cur;
            for(int j=0;j<nums.size();j++) {
                if((i>>j)&1) {
                    cur.push_back(nums[j]);
                }
            }
            ans.push_back(cur);
        }
        return ans;
    }
};
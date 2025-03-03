class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int lesserCnt = 0;
        int greaterCnt = 0;
        int equalCnt = 0;
        for(int& n : nums) {
            if(n > pivot)
                greaterCnt++;
            else if(n < pivot)
                lesserCnt++;
            else
                equalCnt++;
        }
        int l = 0;
        int e = lesserCnt;
        int g = lesserCnt + equalCnt;
        vector<int> ans(nums.size());
        for(int& n : nums) {
            if(n > pivot)
                ans[g++] = n;
            else if(n < pivot)
                ans[l++] = n;
            else
                ans[e++] = n;
        }
        return ans;
    }
};
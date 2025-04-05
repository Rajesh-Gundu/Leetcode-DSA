class Solution {
public:
    int recursion(vector<int>& nums,int i,int curr){
        if(i == nums.size())
            return curr;
        int take = recursion(nums,i+1,curr^nums[i]);
        int skip = recursion(nums,i+1,curr);
        return take + skip;
    }
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        return recursion(nums,0,0);
    }
};
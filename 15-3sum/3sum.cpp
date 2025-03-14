class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++) {
            if(nums[i] > 0) break;
            if(i != 0 && nums[i] == nums[i-1]) continue;
            int l = i+1;
            int r = n-1;
            while(l < r){
                if(nums[l] + nums[r] == (-nums[i])){
                    ans.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                    while(nums[l] == nums[l-1] && l < r) l++;
                }
                else if(nums[l] + nums[r] > (-nums[i])) r--;
                else  l++;
            }
        }
        return ans;
    }
};
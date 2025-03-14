class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> myMap;
        int size = nums.size();
        for(int i=0;i<size;i++){
            int val = target - nums[i];
            if(myMap.find(val) != myMap.end()){
                return {i,myMap[val]};
            }
            myMap.insert({nums[i],i});
        }
        return {};
    }
};
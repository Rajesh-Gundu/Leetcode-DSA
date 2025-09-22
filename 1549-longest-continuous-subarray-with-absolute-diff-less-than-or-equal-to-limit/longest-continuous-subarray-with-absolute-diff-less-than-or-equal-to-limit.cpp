class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        map<int,int> mp;
        int s = 0;
        int e = 0;
        int ans = 0;
        int n = nums.size();
        while(e < n) {
            mp[nums[e]]++;
            while(mp.size() > 1 && abs(mp.rbegin()->first - mp.begin()->first) > limit) {
                if(mp[nums[s]] == 1) {
                    mp.erase(nums[s]);
                }
                else
                    mp[nums[s]]--;
                s++;
            }
            ans = max(ans,e-s+1);
            e++;
        }
        return ans;
    }
};
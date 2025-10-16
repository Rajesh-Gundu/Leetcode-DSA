class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++) {
            if(nums[i] < 0 && (abs(nums[i])%value != 0)) {
                mp[value+nums[i]%value]++;
            }
            else
                mp[abs(nums[i])%value]++;
        }

        int cur = 0;
        while(true) {
            int r = cur%value;
            if(!mp.count(r))
                break;
            mp[r]--;
            if(mp[r] == 0)
                mp.erase(r);
            cur++;
        }
        return cur;
    }
};
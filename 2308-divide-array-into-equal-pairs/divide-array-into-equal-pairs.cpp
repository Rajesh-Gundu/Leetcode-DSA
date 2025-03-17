class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> cnt(501,0);
        for(int& num : nums) {
            cnt[num]++;
        }
        for(int i=1;i<501;i++) {
            if(cnt[i]%2)
                return false;
        }
        return true;
    }
};
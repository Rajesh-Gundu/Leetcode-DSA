class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xorOfAllNumbers = 0;
        int xorOfArrNumbers = 0;
        for(int i=0;i<n;i++) {
            xorOfAllNumbers ^= i;
            xorOfArrNumbers ^= nums[i];
        }
        xorOfAllNumbers ^= n;
        return (xorOfAllNumbers ^ xorOfArrNumbers);
    }
};
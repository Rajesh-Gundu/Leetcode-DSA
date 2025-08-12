class Solution {
public:
    int getSetBitPos(long num) {
        for(int i=0;i<32;i++) {
            if((num>>i)&1)
                return i;
        }
        return 0;
    }
    vector<int> singleNumber(vector<int>& nums) {
        long x = 0;
        for(int& i : nums) {
            x ^= i;
        }
        int zeroGroup = 0;
        int oneGroup = 0;
        int i = getSetBitPos(x);
        for(int& ele : nums) {
            if((ele>>i)&1) {
                oneGroup ^= ele;
            }
            else {
                zeroGroup ^= ele;
            }
        }
        return {oneGroup,zeroGroup};
    }
};
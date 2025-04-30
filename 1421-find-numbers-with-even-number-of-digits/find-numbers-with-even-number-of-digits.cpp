class Solution {
    int digitCnt(int num) {
        int cnt = 0;
        while(num) {
            cnt++;
            num /= 10;
        }
        return cnt;
    }
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(auto& num : nums) {
            if(digitCnt(num)%2 == 0)
                ans++;
        }
        return ans;
    }
};
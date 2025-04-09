class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int p = 0;
        int cnt = 0;
        while(p < n) {
            int i = p;
            int arr[101] = {0};
            bool repeat = false;
            while(i < n) {
                if(arr[nums[i]] > 0) {
                    repeat = true;
                    break;
                }
                arr[nums[i]]++;
                i++;
            }
            if(!repeat)
                break;
            p += 3;
            cnt++;
        }
        return cnt;
    }
};
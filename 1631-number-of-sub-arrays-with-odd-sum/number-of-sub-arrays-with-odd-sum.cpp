class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int oddCount = 0;
        int evenCount = 0;
        if(arr[0]%2) {
            oddCount++;
        }
        else {
            evenCount++;
        }
        long ans = oddCount;
        long sum = arr[0];
        int m = 1e9+7;
        for(int i=1;i<n;i++) {
            sum += arr[i];
            if(sum%2) {
                ans = (ans+evenCount+1)%m;
                oddCount++;
            }
            else {
                ans = (ans+oddCount)%m;
                evenCount++;
            }
        }
        return ans;
    }
};
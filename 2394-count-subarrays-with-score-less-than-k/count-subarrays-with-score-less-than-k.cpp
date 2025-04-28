class Solution {
    int getMaxLen(vector<long long>& prefix,int low,int high,long long k) {
        int idx = -1;
        int start = low;
        while(low <= high) {
            int mid = low + (high -low)/2;
            long long len = mid - start + 1; 
            long long sum = prefix[mid] - (start == 0 ? 0 : prefix[start-1]);
            if(len*sum < k) {
                idx = mid;
                low = mid + 1;
            }
            else 
                high = mid - 1;
        }
        if(idx == -1)
            return -1;
        return idx - start + 1;
    }

public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        vector<long long> prefix(n);
        prefix[0] = nums[0];
        for(int i=1;i<n;i++) {
            prefix[i] = prefix[i-1]+nums[i];
        }
        long long ans = 0;
        for(int i=0;i<n;i++) {
            int len = getMaxLen(prefix,i,n-1,k);
            if(len != -1)
                ans += len;
        }
        return ans;
    }
};
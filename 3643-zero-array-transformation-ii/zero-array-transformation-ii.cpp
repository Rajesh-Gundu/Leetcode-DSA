class Solution {
public:
    bool isValid(vector<int>& nums, vector<vector<int>>& queries,int end) {
        int n = nums.size();
        vector<int> prefix(n,0);
        for(int i=0;i<=end;i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int v = queries[i][2];
            prefix[l] += v;
            if(r+1 < n)
                prefix[r+1] -= v;
        }
        for(int i=1;i<n;i++) {
            prefix[i] += prefix[i-1];
        }
        for(int i=0;i<n;i++) {
            if(prefix[i] < nums[i])
                return false;
        }
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        if(count(nums.begin(),nums.end(),0) == nums.size())
            return 0;
        int ans = -1;
        int lo = 0;
        int hi = queries.size()-1;
        while(lo <= hi) {
            int mid = lo + (hi -lo)/2;
            if(isValid(nums,queries,mid)) {
                ans = mid+1;
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};
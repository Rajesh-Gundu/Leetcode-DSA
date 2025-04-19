class Solution {
    int lowerBound(vector<int>& nums,int lo,int hi,int val) {
        while(lo <= hi) {
            int mid = lo + (hi - lo)/2;
            if(nums[mid] >= val)
                hi = mid - 1;
            else
                lo = mid + 1;
        } 
        return lo;
    }

    long long lowerBound(vector<int>& nums,int val) {
        int l = 0;
        int r = nums.size()-1;
        long long res = 0;
        while(l < r) {
            int sum = nums[l] + nums[r];
            if(sum < val) {
                res += (r-l);
                l++;
            }
            else {
                r--;
            }
        }
        return res; 
    }

public:
    long long binarySearchApproach(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        long long res = 0;
        for(int i=0;i<n;i++) {
            int x = lowerBound(nums,i+1,n-1,lower - nums[i]);
            int y = lowerBound(nums,i+1,n-1,upper-nums[i]+1);
            res += (y-x);
        }
        return res;
    }

    long long twoPointerTech(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        return lowerBound(nums,upper+1) - lowerBound(nums,lower);
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        //return binarySearchApproach(nums,lower,upper);
        return twoPointerTech(nums,lower,upper);
    }
};
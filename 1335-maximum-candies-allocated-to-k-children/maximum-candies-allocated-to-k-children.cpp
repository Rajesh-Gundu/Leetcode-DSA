class Solution {
public:
    bool isValid(vector<int>& candies, long long k,long long limit) {
        long long cnt = 0;
        for(int& p : candies) {
            cnt += p/limit;
            if(cnt >= k)
                return true;
        }
        return false;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int lo = 1;
        int hi = *max_element(candies.begin(),candies.end());
        int ans = 0;
        while(lo <= hi) {
            int mid = lo + (hi -lo)/2;
            if(isValid(candies,k,mid)) {
                ans = mid;
                lo = mid + 1; 
            }
            else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};
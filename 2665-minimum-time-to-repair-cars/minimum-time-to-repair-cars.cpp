class Solution {
public:
    bool isValid(vector<int>& ranks, int cars,long long maxMinutes) {
        long long c = 0;
        int n = ranks.size();
        for(int i=0;i<n;i++) {
            long long t = maxMinutes/ranks[i];
            c += (long long)sqrt(t);
        }
        return (c >= cars);
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long lo = 0;
        long long hi = LLONG_MAX;
        long long ans = hi;
        while(lo <= hi) {
            long long mid = lo + (hi-lo)/2;
            if(isValid(ranks,cars,mid)) {
                ans = mid;
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};
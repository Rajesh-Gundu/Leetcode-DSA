vector<int> primes;
void fillPrimes() {
    int n = 5*1000001;
        bool f[n];
        fill(f,f+n,true);
        f[0] = f[1] = false;
        for(int i=2;i*i<=n;i++) {
            if(f[i]) {
                for(int j=i*i;j<n;j+=i) {
                    f[j] = false;
                }
            }
        }
        for(int i=2;i<n;i++) {
            if(f[i])
                primes.push_back(i);
    }
}

class Solution {
public:
    
    Solution() {
        
    }

    int countPrimes(int n) {
        if(primes.size() == 0)
            fillPrimes();
        int idx = -1;
        int lo = 0;
        int hi = primes.size() - 1;
        while(lo <= hi) {
            int mid = lo + (hi-lo)/2;
            if(primes[mid] < n) {
                idx = mid;
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        } 
        return idx + 1;
    }
};
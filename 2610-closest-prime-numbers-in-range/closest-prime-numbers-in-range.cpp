class Solution {
public:
    vector<int> seive(int left,int right) {
        vector<bool> isPrime(right+1,true);
        isPrime[0] = isPrime[1] = false;
        for(int i=2;i*i<=right;i++) {
            if(isPrime[i]) {
                for(int j=i*i;j<=right;j += i) {
                    isPrime[j] = false;
                }
            }
        }
        vector<int> primes;
        for(int i=left;i<=right;i++) {
            if(isPrime[i])
                primes.push_back(i);
        }
        return primes;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int> primes = seive(left,right);
        if(primes.size() < 2)
            return {-1,-1};
        int idx = 1;
        for(int i=1;i<primes.size();i++) {
            if(primes[i]-primes[i-1] < primes[idx] - primes[idx-1])
                idx = i;
        }
        return {primes[idx-1],primes[idx]};
    }
};
class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        unordered_set<string> unique;
        int d = (n+1)/2;
        int s = pow(10,d-1);
        int e = pow(10,d)-1;
        for(int i=s;i<=e;i++) {
            string lhalf = to_string(i);
            string rhalf = lhalf;
            if(n%2 == 1) {
                rhalf.pop_back();
                
            }
            reverse(rhalf.begin(),rhalf.end());
            string full = lhalf + rhalf;
            long long num = stoll(full);
            if(num % k != 0)
                continue;
            sort(full.begin(),full.end());
            unique.insert(full);
        }

        vector<long long> fact(11);
        fact[0] = 1;
        for(int i=1;i<11;i++) {
            fact[i] = fact[i-1]*i;
        }

        long long cnt = 0;
        for(auto s : unique) {
            vector<int> freq(10,0);
            for(auto ch : s) {
                freq[ch-'0']++;
            }

            int zeros = freq[0];
            int nonZeros = s.length() - zeros;
            long long perm = nonZeros*fact[s.length()-1];

            for(int i=0;i<10;i++) {
                perm /= fact[freq[i]];
            }
            cnt += perm;
        }
        return cnt;
    }
};
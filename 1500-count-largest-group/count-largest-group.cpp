class Solution {
public:
    int getCnt(int n) {
        int sum = 0;
        while(n) {
            sum += (n%10);
            n /= 10;
        }
        return sum;
    }
    int countLargestGroup(int n) {

        unordered_map<int,int> mp;
        int maxi = 0;
        for(int i=1;i<=n;i++) {
            int sum = getCnt(i);
            mp[sum]++;
            maxi = max(mp[sum],maxi);


        }

        int ans = 0;
        for(auto & [_,v] : mp) {
            if(v == maxi)
                ans++;
        }
        return ans;
    }
};
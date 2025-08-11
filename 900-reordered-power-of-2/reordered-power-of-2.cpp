class Solution {
public:
    bool canPick(int num,unordered_map<int,int> mp) {
        while(num) {
            int d = num%10;
            num /= 10;
            if(mp.find(d) == mp.end())
                return false;
            mp[d]--;
            if(mp[d] == 0)
                mp.erase(d);
        }
        return (mp.size() == 0);
    }
    bool reorderedPowerOf2(int n) {
        unordered_map<int,int> mp;
        while(n) {
            mp[n%10]++;
            n /= 10;
        }
        for(int i=0;i<32;i++) {
            if(canPick((1<<i),mp)) {
                return true;
            }
        }
        return false;
    }
};
class Solution {
public:
    bool canPick(int num,int cntN[]) {
        int cntCur[10] = {0};
        while(num) {
            int d = num%10;
            cntCur[d]++;
            num /= 10;
        }
        for(int i=0;i<10;i++) {
            if(cntN[i] != cntCur[i])
                return false;
        }
        return true;
    }
    bool reorderedPowerOf2(int n) {
        int cntN[10] = {0};
        while(n) {
            cntN[n%10]++;
            n /= 10;
        }
        for(int i=0;i<31;i++) {
            if(canPick(1<<i,cntN)) {
                return true;
            }
        }
        return false;
    }
};
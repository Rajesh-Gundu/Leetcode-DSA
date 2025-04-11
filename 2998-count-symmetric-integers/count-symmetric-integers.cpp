class Solution {
    bool isValid(string num) {
        int n = num.length();
        if(n%2) return false;

        int fhalf = 0;
        for(int j=0;j<n/2;j++) {
            fhalf += (num[j]-'0');
        }
        for(int j=n/2;j<n;j++) {
            fhalf -= (num[j]-'0');
        }
        return (fhalf == 0);
    }
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        int i = low;
        while(i <= high) {
            if(isValid(to_string(i)))
                cnt++;
            i += 1;
        }
        return cnt;
    }
};
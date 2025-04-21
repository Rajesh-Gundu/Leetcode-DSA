class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int cur = 0;
        int maxi = 0;
        int mini = 0;
        for(auto& d : differences) {
            cur += d;
            maxi = max(maxi,cur);
            mini = min(mini,cur);
            if(maxi-mini > upper - lower)
               return 0;

        }
        return (upper-lower) - (maxi - mini) + 1;
    }
};
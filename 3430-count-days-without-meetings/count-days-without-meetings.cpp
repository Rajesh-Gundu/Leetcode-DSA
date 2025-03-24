class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int n = meetings.size();
        int c = 0;
        c += meetings[0][0] - 1;
        int hi = meetings[0][1];
        for(int i=1;i<n;i++){
            if(meetings[i][0] > hi){
                c += meetings[i][0] - hi - 1;
                hi = meetings[i][1];
            }
            else{
                if(meetings[i][1] > hi)
                    hi = meetings[i][1];
            }
        }
        if(hi < days)
            c += days-hi;
        return c;
    }
};
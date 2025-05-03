class Solution {
    int getNoOfSwaps(vector<int>& tops, vector<int>& bottoms,int val) {
        int cnt = 0;
        bool possibility = true;
        int n = tops.size();
        for(int i=0;i<n;i++) {
            if(tops[i] == val)
                continue;
            else if(bottoms[i] == val)
                cnt++;
            else {
                possibility = false;
                break;
            }
        }
        if(possibility)
                return cnt;
        return INT_MAX;
    }
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int ans = INT_MAX;
        for(int j=1;j<7;j++) {
            ans = min(ans,getNoOfSwaps(tops,bottoms,j));
            ans = min(ans,getNoOfSwaps(bottoms,tops,j));
        }
        if(ans == INT_MAX)
            return -1;
        return ans;
    }
};
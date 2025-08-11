class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int curSum = 0;
        int ans = 0;
        for(int i=0;i<k;i++) {
            curSum += cardPoints[i];
        }
        ans = curSum;
        int p1 = k-1;
        int p2 = cardPoints.size()-1;
        while(p1 >= 0) {
            curSum -= cardPoints[p1];
            curSum += cardPoints[p2];
            ans = max(ans,curSum);
            p1--;
            p2--;
        }
        return ans;
    }
};
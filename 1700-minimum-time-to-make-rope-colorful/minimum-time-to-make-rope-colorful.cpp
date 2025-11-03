class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        int n = neededTime.size();
        int i = 1;
        while(i < n) {
            if(colors[i] != colors[i-1]) {
                i++;   
                continue;
            }

            int maxi = neededTime[i-1];
            int sum = maxi;
            while(i < n && colors[i] == colors[i-1]) {
                maxi = max(maxi,neededTime[i]);
                sum += neededTime[i];
                i++;
            }
            ans += (sum - maxi);
            i++;
        }
        return ans;
    }
};
class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        int n = original.size();
        int ans = INT_MAX;
        for(int i=1;i<n;i++){
            int dif = original[i] - original[i-1];
            int ub = min(bounds[i][1] - dif,bounds[i-1][1]);
            int lb = max(bounds[i][0] - dif,bounds[i-1][0]);
            if(ub < bounds[i-1][0] || lb > bounds[i-1][1])
                return 0;
            int cnt = ub - lb + 1;
            ans = min(ans,cnt);
            bounds[i][0] = lb + dif;
            bounds[i][1] = ub + dif;
        }
        return ans;
    }
};
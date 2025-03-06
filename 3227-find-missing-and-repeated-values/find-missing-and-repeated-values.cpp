class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<bool> appears(n*n+1,false);
        int a = -1;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                int num = grid[i][j];
                if(appears[num])
                    a = num;
                else
                    appears[num] = true;
            }
        }
        int b;
        for(int i=1;i<appears.size();i++) {
            if(!appears[i]) {
                b = i;
                break;
            }
        }
        return {a,b};
    }
};
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<bool> hasZeroInRow(n,false);
        vector<bool> hasZeroInCol(m,false);

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(matrix[i][j] == 0) {
                    hasZeroInRow[i] = true;
                    hasZeroInCol[j] = true;
                }
            }
        }

        for(int i=0;i<n;i++) {
            if(hasZeroInRow[i]) {
                for(int j=0;j<m;j++)
                    matrix[i][j] = 0;
            }
        }

        for(int j=0;j<m;j++) {
            if(hasZeroInCol[j]) {
                for(int i=0;i<n;i++)
                    matrix[i][j] = 0;
            }
        }
    }
};
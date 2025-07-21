class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int lo = 0;
        int hi = n-1;
        int ind = 0;
        while(lo <= hi) {
            int mid = lo + (hi-lo)/2;
            if(matrix[mid][0] == target) {
                return true;
            }
            else if(matrix[mid][0] < target) {
                ind = mid;
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }

        lo = 0;
        hi = m-1;
        while(lo <= hi) {
            int mid = lo + (hi-lo)/2;
            if(matrix[ind][mid] == target)
                return true;
            else if(matrix[ind][mid] < target)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        return false;
    }
};
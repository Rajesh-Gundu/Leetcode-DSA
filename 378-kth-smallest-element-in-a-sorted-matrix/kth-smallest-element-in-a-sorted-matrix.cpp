class Solution {
public:
    int getCnt(vector<vector<int>>& matrix, int val) {
        int cnt = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0;i<n;i++) {
            int lo = 0;
            int hi = m-1;
            int idx = -1;
            while(lo <= hi) {
                int mid = lo + (hi-lo)/2;
                if(matrix[i][mid] < val) {
                    idx = mid;
                    lo = mid + 1;
                }
                else {
                    hi = mid - 1;
                }
            }
            cnt += (hi+1);
        }
        return cnt;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        int lo = matrix[0][0];
        int hi = matrix[n-1][m-1];
        while(lo <= hi) {
            int mid = lo + (hi-lo)/2;
            
            if(getCnt(matrix,mid) < k) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        return hi;
    }
};
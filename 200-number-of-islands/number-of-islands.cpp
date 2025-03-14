class Solution {
public:
    void dfs(vector<vector<char>>& grid,int i,int j,int n,int m) {
        if(i < 0 || i == n || j < 0 || j == m || grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        dfs(grid,i-1,j,n,m);
        dfs(grid,i,j-1,n,m);
        dfs(grid,i+1,j,n,m);
        dfs(grid,i,j+1,n,m);
    }

    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == '1') {
                    cnt++;
                    dfs(grid,i,j,n,m);
                }
            }
        }
        return cnt;
    }
};
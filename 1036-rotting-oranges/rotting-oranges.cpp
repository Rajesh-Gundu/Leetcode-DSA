class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>> q;
        int fresh = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == 2) {
                    q.push({0,{i,j}});
                }
                else if(grid[i][j] == 1)
                    fresh++;
            }
        }

        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        int time;
        int rotten = 0;
        while(!q.empty()) {
            time = q.front().first;
            int i = q.front().second.first;
            int j = q.front().second.second;
            q.pop();

            for(int k=0;k<4;k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if(ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == 1) {
                    rotten++;
                    grid[ni][nj] = 2;
                    q.push({time+1,{ni,nj}});
                }
            }
        }

        if(fresh != rotten)
            return -1;
        return time;
    }
};
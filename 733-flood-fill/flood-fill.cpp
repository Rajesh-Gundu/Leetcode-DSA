class Solution {

    void dfs(vector<vector<int>>& image, int i, int j, int col,vector<vector<bool>>& vis) {
        vis[i][j] = true;
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        for(int k=0;k<4;k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if(ni >= 0 && ni < image.size() && nj >= 0 && nj < image[0].size() && !vis[ni][nj] && image[ni][nj] == image[i][j]) {
                dfs(image,ni,nj,col,vis);
            }
        }
        image[i][j] = col;
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>> image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<bool>> vis(n,vector<bool> (m,false));
        dfs(image,sr,sc,color,vis);
        return image;
    }
};
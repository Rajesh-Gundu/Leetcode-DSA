class Solution {
    void dfs(int node,vector<bool>& vis,vector<vector<int>>& adj) {
        vis[node] = true;
        for(int v : adj[node]) {
            if(!vis[v])
                dfs(v,vis,adj);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(isConnected[i][j]) {
                    adj[i].push_back(j);
                }
            }
        }

        int cnt = 0;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                cnt++;
                dfs(i,vis,adj);
            }
        }
        return cnt;
    }
};
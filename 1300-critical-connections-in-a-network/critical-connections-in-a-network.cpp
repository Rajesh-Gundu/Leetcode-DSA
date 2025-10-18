class Solution {
    void dfs(int node,int par,vector<vector<int>>& adj,vector<bool>& vis,int& timer,vector<int>& time,vector<int>& low,vector<vector<int>>& ans) {
        vis[node] = true;
        low[node] = time[node] = timer;
        timer++;
        for(auto& v : adj[node]) {
            if(v == par)
                continue;
            if(!vis[v]) {
                dfs(v,node,adj,vis,timer,time,low,ans);
                low[node] = min(low[node],low[v]);
                if(low[v] > time[node]) {
                    ans.push_back({node,v});
                }
            }
            else {
                low[node] = min(low[node],low[v]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto& e : connections) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> time(n,0);
        vector<int> low(n,n+1);
        vector<bool> vis(n,false);
        vector<vector<int>> ans;
        int timer = 1;
        dfs(0,-1,adj,vis,timer,time,low,ans);
        return ans;
    }
};
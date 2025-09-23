class Solution {
    bool isBipartite(int c,int node,vector<vector<int>>& adj,vector<int>& colors) {
        colors[node] = c;
        for(auto v : adj[node]) {
            if(colors[v] == -1) {
                if(!isBipartite(!c,v,adj,colors)) {
                    return false;
                }
            }
            else if(colors[v] == c)
                return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> colors(n,-1);
        for(int i=0;i<n;i++) {
            if(colors[i] == -1 && !isBipartite(0,i,adj,colors)) {
                return false;
            }
        }
        return true;
    }
};
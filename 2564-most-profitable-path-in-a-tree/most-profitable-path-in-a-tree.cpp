class Solution {
    int ans;
public:
    bool findBobPath(vector<vector<int>>& adj,int node,int steps,vector<int>& bobSteps,int parent) {
        bobSteps[node] = steps;
        if(node == 0)
            return true;
        for(auto& v : adj[node]) {
            if(v != parent) {
                if(findBobPath(adj,v,steps+1,bobSteps,node))
                    return true;
            }
        }
        bobSteps[node] = -1;
        return false;
    }

    void alicePath(vector<vector<int>>& adj,int node,int steps,vector<int>& bobSteps,int parent,int score,vector<int>& amount) {
        if(bobSteps[node] == -1 || steps < bobSteps[node])
            score += amount[node];
        else if(bobSteps[node] == steps)
            score += (amount[node]/2);
        if(node != 0 && adj[node].size() == 1) {
            ans = max(ans,score);
            return;
        }
        for(auto& v : adj[node]) {
            if(v != parent) {
                alicePath(adj,v,steps+1,bobSteps,node,score,amount);
            }
        }
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        ans = INT_MIN;
        int n = edges.size()+1;
        vector<vector<int>> adj(n);
        for(auto& e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> bobSteps(n,-1);
        findBobPath(adj,bob,0,bobSteps,-1);
        // for(int i=0;i<n;i++)
        //     cout << bobSteps[i] << " ";
        alicePath(adj,0,0,bobSteps,-1,0,amount);
        return ans;
    }
};
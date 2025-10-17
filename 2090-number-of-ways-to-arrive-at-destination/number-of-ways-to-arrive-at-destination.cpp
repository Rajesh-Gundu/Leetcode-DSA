class Solution {
public:
    typedef pair<long long,int> P;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<P>> adj(n);
        for(auto& r : roads) {
            int u = r[0];
            int v = r[1];
            int w = r[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        vector<long long> dist(n,LLONG_MAX);
        vector<int> ways(n,0);
        dist[0] = 0;
        ways[0] = 1;
        priority_queue<P,vector<P>,greater<P>> pq;
        pq.push({0,0});
        int m = 1e9+7;
        while(!pq.empty()) {
            long long d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if(d > dist[u])
                continue;
            for(auto it : adj[u]) {
                int v = it.first;
                int w = it.second;
                long long cur = 0ll + d + w;
                if(dist[v] > cur) {
                    dist[v] = cur;
                    ways[v] = ways[u];
                    pq.push({cur,v});
                }
                else if(dist[v] == cur) {
                    ways[v] = (0ll + ways[v] + ways[u])%m;
                }
            }
        }
        return ways[n-1];
    }
};
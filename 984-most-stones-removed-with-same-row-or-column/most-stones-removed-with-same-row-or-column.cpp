class DisjointSet{
    vector<int> parent;
    vector<int> cap;
public :
    DisjointSet(int n){
        parent.resize(n+1);
        cap.resize(n+1);
        for(int i=0;i<n+1;i++){
            parent[i] = i;
            cap[i] = 1;
        }
    }
    
    int findParent(int node){
        if(parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]);
    }
    
    void unionBySize(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu == pv)
            return;
        int usize = cap[pu];
        int vsize = cap[pv];
        if(usize >= vsize){
            parent[pv] = pu;
            cap[pu] += cap[pv];
            cap[pv] = 1;
        }
        else{
            parent[pu] = pv;
            cap[pv] += cap[pu];
            cap[pu] = 1;
        }
    }
    
    bool isSameComponent(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);
        return pu == pv;
    }

    int getTotalComponents() {
        int cnt = 0;
        for(auto c : cap) {
            if(c > 1)
                cnt++;
        }
        return cnt;
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        DisjointSet ds(2*1e4+1);
        for(auto& s : stones) {
            int i = s[0];
            int j = 1e4+1+s[1];
            ds.unionBySize(i,j);
        }
        return stones.size()-ds.getTotalComponents();
    }
};
class DisjointSet{
    vector<int> parent;
    vector<int> rank;
    vector<int> cap;
public :
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1);
        cap.resize(n+1);
        for(int i=0;i<n+1;i++){
            rank[i] = 0;
            parent[i] = i;
            cap[i] = 1;
        }
    }
    
    int findParent(int node){
        if(parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]);
    }
    
    void unionByRank(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu == pv)
            return;
        int urank = rank[pu];
        int vrank = rank[pv];
        if(urank >= vrank){
            parent[pv] = pu;
            if(urank == vrank)
                rank[pu]++;
        }
        else{
            parent[pu] = pv;
        }
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
        }
        else{
            parent[pu] = pv;
            cap[pv] += cap[pu];
        }
    }
    
    bool isSameComponent(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);
        return pu == pv;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++) {
            for(int j=1;j<accounts[i].size();j++) {
                string cur = accounts[i][j];
                if(mp.count(cur)) {
                    ds.unionBySize(i,mp[cur]);
                }
                else {
                    mp[cur] = i;
                }
            }
        }

        vector<vector<string>> merged(n);
        for(auto& it : mp) {
            string mail = it.first;
            int idx = ds.findParent(it.second);
            merged[idx].push_back(mail);
        }

        vector<vector<string>> ans;
        for(int i=0;i<n;i++) {
            if(merged[i].size() == 0)
                continue;
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            sort(merged[i].begin(),merged[i].end());
            for(auto& s : merged[i]) {
                temp.push_back(s);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
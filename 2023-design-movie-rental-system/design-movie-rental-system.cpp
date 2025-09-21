class MovieRentingSystem {
public:
    set<vector<int>> rented;
    map<int,set<vector<int>>> movie;
    vector<map<int,int>> shop;

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        shop.resize(n);
        for(auto& e : entries) {
            int s = e[0];
            int m = e[1];
            int p = e[2];

            shop[s][m] = p;
            movie[m].insert({p,s});
        } 
    }
    
    vector<int> search(int m) {
        vector<int> ans;
        for(auto it : movie[m]) {
            int s = it[1];
            ans.push_back(s);
            if(ans.size() == 5) 
                break;
        }
        return ans;
    }
    
    void rent(int s, int m) {
        int p = shop[s][m];
        rented.insert({p,s,m});
        movie[m].erase({p,s});
    }
    
    void drop(int s, int m) {
        int p = shop[s][m];
        rented.erase({p,s,m});
        movie[m].insert({p,s});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ans;
        for(auto it : rented) {
            int p = it[0];
            int s = it[1];
            int m = it[2];
            ans.push_back({s,m});

            if(ans.size() == 5)
                break;
        }
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
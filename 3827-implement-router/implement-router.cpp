class Router {
public:
    int maxSize;
    queue<vector<int>> router;
    unordered_map<int,vector<int>> mp;
    set<vector<int>> reached;

    Router(int memoryLimit) {
        maxSize = memoryLimit;
        while(!router.empty())
            router.pop();

        mp.clear();
        reached.clear();
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        if(reached.count({source,destination,timestamp}))
            return false;
        if(router.size() == maxSize) {
            int des = router.front()[1];
            reached.erase(router.front());
            router.pop();
            mp[des][0]++;
        }
        router.push({source,destination,timestamp});
        reached.insert({source,destination,timestamp});
        if(!mp.count(destination)) {
            mp[destination].push_back(1);
        }
        mp[destination].push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if(router.empty())
            return {};
        auto ans = router.front();
        router.pop();
        reached.erase(ans);
        int des = ans[1];
        mp[des][0]++;
        return ans;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        if(!mp.count(destination))
            return 0;
        int s = mp[destination][0];
        auto l = lower_bound(mp[destination].begin()+s,mp[destination].end(),startTime);
        auto r = upper_bound(mp[destination].begin()+s,mp[destination].end(),endTime);
        return distance(l,r);
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
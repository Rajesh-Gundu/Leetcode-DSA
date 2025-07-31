class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize != 0)
            return false;
        unordered_map<int,int> mp;
        for(int cur : hand) {
            mp[cur]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto i : mp) {
            pq.push({i.first,i.second});
        }
        while(!pq.empty()) {
            int s = groupSize-1;
            vector<pair<int,int>> remain;
            int prev = pq.top().first;
            if(pq.top().second > 1)
                remain.push_back({prev,pq.top().second-1});
            pq.pop();
            while(s) {
                int cur = pq.top().first;
                if(cur != prev-1)
                    return false;
                if(pq.top().second > 1)
                    remain.push_back({cur,pq.top().second-1});
                pq.pop();
                s--;
                prev = cur;
            }
            for(int i=0;i<remain.size();i++) {
                pq.push(remain[i]);
            }
        }
        return true;
    }
};
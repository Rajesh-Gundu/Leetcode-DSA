class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> map;
        for(auto i : answers) {
            map[i]++;
        }

        int ans = 0;
        for(auto& i : map) {
            int noOfGroups = ceil(double(i.second)/(i.first+1));
            ans += noOfGroups*(i.first+1);
        }
        return ans;
    }
};
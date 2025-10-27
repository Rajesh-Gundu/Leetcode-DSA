class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        int prev = 0;
        for(auto& row : bank) {
            int cnt = 0;
            for(auto& ch : row)
                if(ch == '1')   cnt++;
            
            ans += (cnt*prev);
            prev = (cnt) ? cnt : prev;
        }
        return ans;
    }
};
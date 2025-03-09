class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int len = 1;
        int ans = 0;
        int prev = colors[0];
        for(int i=1;i<n;i++) {
            if(colors[i] != prev) {
                if(len < k)
                    len++;
                if(len == k)
                    ans++;
            }
            else {
                len = 1;
            }
            prev = colors[i];
        }

        if(colors[0] == colors[n-1])
            return ans;
        
        for(int i=0;i<k-1;i++) {
            if(colors[i] != prev) {
                if(len < k)
                    len++;
                if(len == k)
                    ans++;
            }
            else {
                break;
            }
            prev = colors[i];
        }

        return ans;
    }
};
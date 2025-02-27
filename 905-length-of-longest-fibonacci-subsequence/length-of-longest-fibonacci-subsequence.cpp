class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++) {
            mp[arr[i]] = i;
        }
        int ans = 0;
        for(int i=0;i<n-2;i++) {
            for(int j=i+1;j<n-1;j++) {
                int a = arr[i];
                int b = arr[j];
                int c = a+b;
                int cnt = 2;
                while(mp.count(c)) {
                    cnt++;
                    a = b;
                    b = c;
                    c = a+b;
                }
                if(cnt > 2) {
                    ans = max(ans,cnt);
                }
            }
        }
        return ans;
    }
};
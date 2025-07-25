class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int mod = 1e9+7;
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--) {
            while(!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            nse[i] = (st.empty() ? n : st.top());
            st.push(i);
        }

        long long sum = 0;
        while(!st.empty())
            st.pop();

        for(int i=0;i<n;i++) {
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            int pse = (st.empty() ? -1 : st.top());
            st.push(i);

            long long cnt = 0;
            long long l = (i-pse);
            long long r = (nse[i]-i);
            cnt = ((l+r-1) + (l-1)*(r-1))*arr[i]*1ll;
            sum = (sum+cnt)%mod; 
        }
        return sum;
    }
};
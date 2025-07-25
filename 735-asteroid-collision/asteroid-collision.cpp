class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        for(int i=0;i<n;i++) {
            bool isEqual = false;
            while(!st.empty() && ((asteroids[i] < 0 && st.top() > 0))) {
                int curVal = abs(asteroids[i]);
                int topVal = abs(st.top());
                if(curVal == topVal) {
                    st.pop();
                    isEqual = true;
                    break;
                }
                else if(curVal < topVal) {
                    isEqual = true;
                    break;
                }
                else {
                    st.pop();
                }
            }
            if(!isEqual)
                st.push(asteroids[i]);
        }
        if(st.empty())
            return {};
        int ansL = st.size();
        vector<int> ans(ansL);
        for(int i=ansL-1;i>=0;i--) {
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};
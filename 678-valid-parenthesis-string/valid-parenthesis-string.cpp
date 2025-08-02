class Solution {
public:
    bool checkValidString(string s) {
        stack<pair<char,int>> st;
        int stars = 0;
        for(char ch : s) {
            if(ch == '(') {
                st.push({ch,stars});
            }
            else if(ch == '*') {
                stars++;
            }
            else {
                if(st.empty() && stars == 0)
                    return false;
                if(!st.empty())
                    st.pop();
                else
                    stars--;
            }
        }
        while(!st.empty()) {
            int cnt = st.top().second;
            st.pop();
            if(stars - cnt == 0)
                return false;
            stars--;
        }
        return true;
    }
};
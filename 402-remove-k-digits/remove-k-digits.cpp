class Solution {
public:
    string removeKdigits(string s, int k) {
        if(k >= s.length())
            return "0";
        stack<char> st;
        for(char ch : s) {
            while(k && !st.empty() && st.top() > ch) {
                st.pop();
                k--;
            }
            st.push(ch);
        }
        while(k--) {
            st.pop();
        }
        string ans;
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        while(ans.length() > 0 && ans.back() == '0')
            ans.pop_back();
        if(ans.length() == 0) 
            return "0";
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
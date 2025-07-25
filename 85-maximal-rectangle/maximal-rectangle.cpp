class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int ans = INT_MIN;
        for(int i=0;i<=n;i++) {
            while((i == n) || (!st.empty() && heights[i] < heights[st.top()])) {
                if(st.empty())
                    break;
                int idx = st.top();
                st.pop();
                int left = (st.empty() ? -1 : st.top());
                int width = (i-left-1);
                int height = heights[idx];
                int area = width*height;
                ans = max(ans,area);
            }
            st.push(i);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea = INT_MIN;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> hist(m,0);
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(matrix[i][j] == '0')
                    hist[j] = 0;
                else
                    hist[j]++;
            }
            maxArea = max(maxArea, largestRectangleArea(hist));
        }
        return maxArea;
    }
};
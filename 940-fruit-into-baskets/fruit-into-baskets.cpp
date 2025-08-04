class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int idx1 = 0;
        int idx2 = -1;
        int i = 0;
        int j = 1;
        int ans = 1;
        while(j < n) {
            if(fruits[j] == fruits[idx1]) {
                idx1 = j;
            }
            else if(idx2 == -1 || fruits[j] == fruits[idx2]) {
                idx2 = j;
            }
            else {
                i = min(idx1,idx2)+1;
                idx1 = (i == idx1+1 ? idx2 : idx1);
                idx2 = j;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
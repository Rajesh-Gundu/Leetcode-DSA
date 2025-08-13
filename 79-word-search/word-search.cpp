class Solution {
public:
    int n;
    int m;
    bool checkInvalidCell(int i,int j) {
        return (i < 0 || i >= n || j < 0 || j >= m);
    }

    bool check(int i,int j,int idx, string& word,vector<vector<char>>& board,vector<vector<bool>>& vis) {
        if(idx == word.length())
            return true;
        if(checkInvalidCell(i,j) || vis[i][j] || board[i][j] != word[idx])
            return false;
        vis[i][j] = true;
        bool l = check(i,j-1,idx+1,word,board,vis);
        bool r = check(i,j+1,idx+1,word,board,vis);
        bool u = check(i-1,j,idx+1,word,board,vis);
        bool d = check(i+1,j,idx+1,word,board,vis);
        vis[i][j] = false;
        return (l || r || u || d);

    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        vector<vector<bool>> vis(n,vector<bool> (m,false));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(board[i][j] == word[0]) {
                    if(check(i,j,0,word,board,vis))
                        return true;
                }
            }
        }
        return false;
    }
};
class Solution {
public:
    void solve(string tiles,vector<bool>& used,unordered_set<string>& seq,string cur) {
        seq.insert(cur);
        for (int pos = 0; pos < tiles.length(); ++pos) {
            if (!used[pos]) {
                used[pos] = true;
                solve(tiles,used,seq,cur+tiles[pos]);
                used[pos] = false;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        unordered_set<string> seq;
        vector<bool> used(tiles.length(), false);
        solve(tiles,used,seq,"");
        return seq.size()-1;
    }
};
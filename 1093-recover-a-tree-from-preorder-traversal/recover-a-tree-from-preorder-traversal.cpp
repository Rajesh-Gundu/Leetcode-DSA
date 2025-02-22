/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int idx;
    TreeNode* solve(string& traversal,int depth) {
        if(idx >= traversal.length())
            return nullptr;
        int j = idx;
        while(traversal[j] == '-')
            j++;
        int dashes = j-idx;
        if(depth != dashes)
            return nullptr;
        int val = 0;
        while(j < traversal.length() && traversal[j] != '-') {
            val = val*10 + (traversal[j]-'0');
            j++;
        }
        TreeNode* node = new TreeNode(val);
        idx = j;
        node->left = solve(traversal,depth+1);
        node->right = solve(traversal,depth+1);
        return node;
    }

    TreeNode* recoverFromPreorder(string traversal) {
        idx = 0;
        return solve(traversal,0);
    }
};
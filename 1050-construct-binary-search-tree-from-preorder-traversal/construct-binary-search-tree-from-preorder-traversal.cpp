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
    TreeNode* constructBST(vector<int>& preorder,int lo,int hi) {
        if(lo > hi) return nullptr;
        TreeNode* root = new TreeNode(preorder[lo]);
        int i = lo+1;
        while(i <= hi && preorder[i] < preorder[lo])
            i++;
        root->left = constructBST(preorder,lo+1,i-1);
        root->right = constructBST(preorder,i,hi);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return constructBST(preorder,0,preorder.size()-1);
    }
};
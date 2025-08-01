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
    bool checkValidity(TreeNode* root,long A,long B) {
        if(root == nullptr)
            return true;
        return (root->val > A && root->val < B) && (checkValidity(root->left,A,root->val)) && (checkValidity(root->right,root->val,B));
    }

    bool isValidBST(TreeNode* root) {
        return checkValidity(root,LONG_MIN,LONG_MAX);
    }
};
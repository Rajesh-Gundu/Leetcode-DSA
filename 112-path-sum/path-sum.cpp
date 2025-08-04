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
    bool check(TreeNode* root, int targetSum,int curSum) {
        if(root == nullptr)
            return false;
        if(root->right == nullptr && root->left == nullptr) {
            return (targetSum == curSum+root->val);
        }
        return (check(root->right,targetSum,curSum+root->val) || check(root->left,targetSum,curSum+root->val));
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return check(root,targetSum,0);
    }
};
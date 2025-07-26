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
    int getVal(TreeNode* root, int& cnt,int k) {
        if(root == nullptr)
            return INT_MAX;
        int l = getVal(root->left,cnt,k);
        cnt++;
        if(cnt == k)
            return root->val;
        int r = getVal(root->right,cnt,k);
        return min(l,r);
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        return getVal(root,cnt,k);
    }
};
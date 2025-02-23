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
    TreeNode* solve(vector<int>& preorder,unordered_map<int,int>& mp,int low,int high,int& idx) {
        if(idx == preorder.size() || high < low)
            return nullptr;
        int val = preorder[idx];
        if(mp[val] > high)
            return nullptr;
        idx++;
        TreeNode* node = new TreeNode(val);
        node->left = solve(preorder,mp,low,mp[val]-1,idx);
        node->right = solve(preorder,mp,low,mp[val]-1,idx);
        return node;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int idx = 0;
        unordered_map<int,int> mp;
        int n = postorder.size();
        for(int i=0;i<n;i++)
            mp[postorder[i]] = i;
        return solve(preorder,mp,0,n-1,idx);
    }
};
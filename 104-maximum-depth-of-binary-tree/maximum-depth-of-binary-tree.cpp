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
    void findDepth(TreeNode* root,int curDepth,int& ans) {
        if(root == nullptr)
            return;
        ans = max(ans,curDepth);
        findDepth(root->left,curDepth+1,ans);
        findDepth(root->right,curDepth+1,ans);
    }
    int maxDepth(TreeNode* root) {
        // int ans = 0;
        // findDepth(root,1,ans);
        // return ans;
        if(root == nullptr)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while(!q.empty()) {
            ans++;
            int s = q.size();
            for(int i=0;i<s;i++) {
                TreeNode* tmp = q.front();
                q.pop();
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
            }
        }
        return ans;
    }
};
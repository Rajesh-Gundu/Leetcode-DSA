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
    void check(TreeNode* root,unordered_set<TreeNode*>& dnodes,int & cnt) {
        if(root == nullptr)
            return;
        if(dnodes.count(root))
            cnt++;
        check(root->left,dnodes,cnt);
        check(root->right,dnodes,cnt);
    }
    TreeNode* solve(TreeNode* root,unordered_set<TreeNode*>& dnodes) {
        int cnt = 0;
        check(root->left,dnodes,cnt);
        if(cnt == dnodes.size()) {
           return solve(root->left,dnodes); 
        }
        else if(cnt == 0) {
            return solve(root->right,dnodes);
        }
        return root;
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        unordered_set<TreeNode*> lastLevel;
        while(!q.empty()) {
            int s = q.size();
            lastLevel.clear();
            for(int i=0;i<s;i++) {
                TreeNode* cur = q.front();
                q.pop();
                lastLevel.insert(cur);
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
        }
        if(lastLevel.size() == 1)
            return *(lastLevel.begin());
        return solve(root,lastLevel);
    }
};
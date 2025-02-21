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
class FindElements {
public:
    unordered_set<int> data;
    void filldata(TreeNode* root,int x) {
        if(root == nullptr)
            return;
        data.insert(x);
        if(root->left)
            filldata(root->left,2*x+1);
        if(root->right)
            filldata(root->right,2*x+2);
    }
    FindElements(TreeNode* root) {
        data.clear();
        filldata(root,0);
    }
    
    bool find(int target) {
        if(data.count(target))
            return true;
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
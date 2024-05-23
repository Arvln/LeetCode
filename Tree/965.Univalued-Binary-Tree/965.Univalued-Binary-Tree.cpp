class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        return dfs(root, root->val);
    }
    bool dfs(TreeNode *node, int val)
    {
        if (node==NULL) return true;
        else if (node->val!=val) return false;
        else if (dfs(node->left, val)==false) return false;
        else if (dfs(node->right, val)==false) return false;
        else return true;
    }
};
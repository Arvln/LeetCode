class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_MIN, LONG_MAX);
    }
    bool dfs(TreeNode *node, long low, long high)
    {
        if (node==NULL) return true;
        else if (node->val<=low||node->val>=high) return false;
        else if (dfs(node->left, low, node->val)==false) return false;
        else if (dfs(node->right, node->val, high)==false) return false;
        else return true;
    }
};
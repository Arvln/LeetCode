class Solution {
    int ret=0;
public:
    int maxAncestorDiff(TreeNode* root) {
        dfs(root, root->val, root->val);
        return ret;
    }
    void dfs(TreeNode *node, int minVal, int maxVal)
    {
        if (node==NULL) return;

        minVal=min(minVal, node->val);
        maxVal=max(maxVal, node->val);
        ret=max({ret, maxVal-node->val, node->val-minVal});
        dfs(node->left, minVal, maxVal);
        dfs(node->right, minVal, maxVal);
    }
};
class Solution {
    int ret=INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ret;
    }
    int dfs(TreeNode *node)
    {
        if (node==NULL) return 0;

        int left=max(dfs(node->left), 0);
        int right=max(dfs(node->right), 0);
        ret=max(ret, node->val+left+right);
        return node->val+max(left, right);
    }
};
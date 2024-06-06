class Solution {
    int ret=0;
public:
    int longestZigZag(TreeNode* root) {
        dfs(root, NULL);
        return ret;
    }
    int dfs(TreeNode *node, TreeNode *parent)
    {
        if (node==NULL) return 0;

        int left=dfs(node->left, node);
        int right=dfs(node->right, node);
        ret=max({ret, left, right});

        if (parent==NULL) return 0;
        else if (parent->left==node) return right+1;
        else return left+1;
    }
};
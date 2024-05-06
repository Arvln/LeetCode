class Solution {
    int ret=1;
public:
    int longestConsecutive(TreeNode *root) {
        dfs(root, NULL);
        return ret;
    }
    int dfs(TreeNode *node, TreeNode *parent)
    {
        if (node==NULL) return 1;

        int left=dfs(node->left, node);
        int right=dfs(node->right, node);
        ret=max({ret, left, right});

        if (parent==NULL) return -1;
        else if (node->val==parent->val+1) return max(left, right)+1;
        else return 1;
    }
};
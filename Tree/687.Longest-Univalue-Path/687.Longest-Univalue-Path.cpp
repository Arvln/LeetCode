class Solution {
    int ret=0;
public:
    int longestUnivaluePath(TreeNode* root) {
        dfs(root, INT_MIN);
        return ret;
    }
    int dfs(TreeNode *node, int parent)
    {
        if (node==NULL) return 0;

        int left=dfs(node->left, node->val);
        int right=dfs(node->right, node->val);
        ret=max(ret, left+right);

        if (node->val==parent) return max(left, right)+1;
        else return 0;
    }
};
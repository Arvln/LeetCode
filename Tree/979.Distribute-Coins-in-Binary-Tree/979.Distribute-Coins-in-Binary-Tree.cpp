class Solution {
    int ret=0;
public:
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return ret;
    }
    int dfs(TreeNode *node)
    {
        if (node==NULL) return 0;

        int left=dfs(node->left);
        int right=dfs(node->right);
        ret+=abs(left)+abs(right);
        return node->val+left+right-1;
    }
};
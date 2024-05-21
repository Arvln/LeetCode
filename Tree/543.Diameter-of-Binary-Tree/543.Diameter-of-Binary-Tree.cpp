class Solution {
    int ret=0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return ret;
    }
    int dfs(TreeNode *node)
    {
        if (node==NULL) return 0;

        int left=dfs(node->left);
        int right=dfs(node->right);
        ret=max(ret, left+right);
        return max(left, right)+1;
    }
};
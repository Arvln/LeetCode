class Solution {
    int maxDepth=0;
    TreeNode *ret;
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        dfs(root, 0);
        return ret;
    }
    int dfs(TreeNode *node, int depth)
    {
        if (node==NULL) return depth;

        int left=dfs(node->left, depth+1);
        int right=dfs(node->right, depth+1);
        maxDepth=max(maxDepth, max(left, right));
        if (left==right&&left==maxDepth) ret=node;
        return max(left, right);
    }
};
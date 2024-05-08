class Solution {
    int ret, maxDepth=-1;
public:
    int findBottomLeftValue(TreeNode* root) {
        dfs(root, 0);
        return ret;
    }
    void dfs(TreeNode *node, int depth)
    {
        if (node==NULL) return;
        else if (depth>maxDepth)
        {
            maxDepth=depth;
            ret=node->val;
        }

        dfs(node->left, depth+1);
        dfs(node->right, depth+1);
    }
};
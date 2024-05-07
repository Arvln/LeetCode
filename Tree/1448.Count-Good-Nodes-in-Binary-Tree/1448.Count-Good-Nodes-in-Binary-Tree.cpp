class Solution {
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
    int dfs(TreeNode *node, int maxVal)
    {
        if (node==NULL) return 0;

        int ret=node->val>=maxVal;
        maxVal=max(maxVal, node->val);
        ret+=dfs(node->left, maxVal);
        ret+=dfs(node->right, maxVal);
        return ret;
    }
};
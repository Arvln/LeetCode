class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (root==NULL) return 0;
        return dfs(root, targetSum)+pathSum(root->left, targetSum)+pathSum(root->right, targetSum);
    }
    int dfs(TreeNode *node, long targetSum)
    {
        if (node==NULL) return 0;

        int count=node->val==targetSum;
        count+=dfs(node->left, targetSum-node->val);
        count+=dfs(node->right, targetSum-node->val);
        return count;
    }
};
class Solution {
public:
    int countUnivalSubtrees(TreeNode *root) {
        if (root==NULL) return 0;

        int ret=dfs(root, root->val);
        ret+=countUnivalSubtrees(root->left);
        ret+=countUnivalSubtrees(root->right);
        return ret;
    }
    int dfs(TreeNode *node, int val)
    {
        if (node==NULL) return 1;
        else if (node->val!=val) return 0;
        else if (dfs(node->left, val)==0) return 0;
        else if (dfs(node->right, val)==0) return 0;
        else return 1;
    }
};
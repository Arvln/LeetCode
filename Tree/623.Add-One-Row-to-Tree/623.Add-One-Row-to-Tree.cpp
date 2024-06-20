class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        return dfs(root, NULL, val, depth);
    }
    TreeNode* dfs(TreeNode *node, TreeNode *parent, int val, int depth)
    {
        if (depth==1)
        {
            if (parent==NULL||parent->left==node) return new TreeNode(val, node, NULL);
            else return new TreeNode(val, NULL, node);
        }
        else if (node==NULL) return NULL;

        node->left=dfs(node->left, node, val, depth-1);
        node->right=dfs(node->right, node, val, depth-1);
        return node;
    }
};
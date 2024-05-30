class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        return dfs(root, root->val);
    }
    int dfs(TreeNode *node, int parent)
    {
        if (node==NULL) return -1;
        else if (node->val!=parent) return node->val;

        int left=dfs(node->left, node->val);
        int right=dfs(node->right, node->val);

        if (left==-1) return right;
        else if (right==-1) return left;
        else return min(left, right);
    }
};
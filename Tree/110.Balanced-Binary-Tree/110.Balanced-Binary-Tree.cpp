class Solution {
    bool ret=true;
public:
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return ret;
    }
    int dfs(TreeNode *node)
    {
        if (node==NULL) return 0;

        int left=dfs(node->left);
        int right=dfs(node->right);
        if (abs(left-right)>1) ret=false;
        return max(left, right)+1;
    }
};
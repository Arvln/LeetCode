class Solution {
    int ret=0;
public:
    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return ret;
    }
    int dfs(TreeNode *node, int val)
    {
        if (node==NULL) return 0;

        val=val*10+node->val;
        int left=dfs(node->left, val);
        int right=dfs(node->right, val);
        int depth=max(left, right);

        if (depth==0) ret+=val;
        return depth+1;
    }
};
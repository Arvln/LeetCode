class Solution {
    long ret=0;
    int M=1e9+7;
    int total;
public:
    int maxProduct(TreeNode* root) {
        total=sum(root);
        dfs(root);
        return ret%M;
    }
    int sum(TreeNode *node)
    {
        if (node==NULL) return 0;
        else return node->val+sum(node->left)+sum(node->right);
    }
    int dfs(TreeNode *node)
    {
        if (node==NULL) return 0;

        int left=dfs(node->left);
        int right=dfs(node->right);
        long subSum=node->val+left+right;
        ret=max(ret, subSum*(total-subSum));
        return subSum;
    }
};
class Solution {
    int sum=0;
public:
    int sumRootToLeaf(TreeNode* root) {
        dfs(root, 0);
        return sum;
    }
    int dfs(TreeNode *node, int path)
    {
        if (node==NULL) return 0;
        
        path=(path<<1)+node->val;

        int left=dfs(node->left, path);
        int right=dfs(node->right, path);
        int depth=max(left, right)+1;

        if (depth==1) sum+=path;
        return depth;
    }
};
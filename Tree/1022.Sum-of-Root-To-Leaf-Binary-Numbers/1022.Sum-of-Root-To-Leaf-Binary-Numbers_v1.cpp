class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
    int dfs(TreeNode *node, int path)
    {
        if (node==NULL) return 0;
        
        path=(path<<1)+node->val;
        if (node->left==NULL&&node->right==NULL) return path;
        else return dfs(node->left, path)+dfs(node->right, path);
    }
};
class Solution {
    int ret=0;
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        dfs(root, 0);
        return ret;
    }
    void dfs(TreeNode *node, int path)
    {
        if (node==NULL) return;

        path^=1<<node->val;

        if (node->left==NULL&&node->right==NULL&&(path&(path-1))==0)
            ret++;

        dfs(node->left, path);
        dfs(node->right, path);
    }
};
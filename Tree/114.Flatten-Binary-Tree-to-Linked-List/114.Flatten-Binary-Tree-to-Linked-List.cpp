class Solution {
public:
    void flatten(TreeNode* root) {
        dfs(root);
    }
    TreeNode* dfs(TreeNode* root)
    {
        if (root==NULL) return NULL;

        TreeNode* right=dfs(root->right);
        root->right=dfs(root->left);
        root->left=NULL;
        TreeNode* cur=root;
        while (cur->right!=NULL)
            cur=cur->right;
        cur->right=right;
        return root;
    }
};
class Solution {
    TreeNode *prev, *x, *y;
public:
    void recoverTree(TreeNode* root) {
       dfs(root);
       swap(x->val, y->val);
    }
    void dfs(TreeNode *node)
    {
         if (node==NULL) return;

        dfs(node->left);
        if (prev!=NULL&&prev->val>node->val)
        {
            y=node;
            if (x==NULL) x=prev;
        }
        prev=node;
        dfs(node->right);
    }
};
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return dfs(root, root);
    }
    bool dfs(TreeNode *p, TreeNode *q)
    {
        if (p==NULL) return q==NULL;
        else if (q==NULL) return false;
        else return p->val==q->val&&dfs(p->left, q->right)&&dfs(p->right, q->left);
    }
};
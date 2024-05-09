class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if (root==NULL) return NULL;

        TreeNode *left=sufficientSubset(root->left, limit-root->val);
        TreeNode *right=sufficientSubset(root->right, limit-root->val);

        if (root->left==NULL&&root->right==NULL)
        {
            if (limit-root->val>0) return NULL;
            else return root;
        }
        else if (left==NULL&&right==NULL) return NULL;
        else
        {
            root->left=left;
            root->right=right;
            return root;
        }
    }
};
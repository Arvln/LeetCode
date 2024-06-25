class Solution {
    TreeNode *pre;
public:
    TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {
        if (root==NULL) return NULL;
        
        TreeNode *left=inorderSuccessor(root->left, p);
        if (left!=NULL) return left;
        else if (pre!=NULL&&pre==p) return root;
        pre=root;
        TreeNode *right=inorderSuccessor(root->right, p);
        return right;
    }
};
class Solution {
    int sum=0;
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root==NULL) return sum;

        if (root->left!=NULL&&root->left->left==NULL&&root->left->right==NULL)
            sum+=root->left->val;
        
        sumOfLeftLeaves(root->left);
        sumOfLeftLeaves(root->right);
        return sum;
    }
};
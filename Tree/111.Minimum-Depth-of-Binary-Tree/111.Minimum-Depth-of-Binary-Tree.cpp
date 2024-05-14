class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root==NULL) return 0;

        int left=minDepth(root->left);
        int right=minDepth(root->right);

        if (root->left==NULL) return right+1;
        else if (root->right==NULL) return left+1;
        else return min(left, right)+1;
    }
};
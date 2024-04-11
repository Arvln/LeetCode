class Solution {
    int prev=INT_MIN/2;
    int ret=INT_MAX;
public:
    int getMinimumDifference(TreeNode* root) {
        if (root==NULL) return ret;

        getMinimumDifference(root->left);
        ret=min(ret, root->val-prev);
        prev=root->val;
        getMinimumDifference(root->right);
        return ret;
    }
};
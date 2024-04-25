class Solution {
    double diff=INT_MAX;
    int ret;
public:
    int closestValue(TreeNode *root, double target) {
        if (root==NULL) return ret;
        else if (abs(root->val-target)<diff)
        {
            diff=abs(root->val-target);
            ret=root->val;
        }
        
        if (root->val>target) return closestValue(root->left, target);
        else return closestValue(root->right, target);
    }
};
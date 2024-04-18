class Solution {
    int count=0;
public:
    int kthSmallest(TreeNode* root, int k) {
        if (root==NULL) return -1;

        int left=kthSmallest(root->left, k);
        count++;
        if (left!=-1) return left;
        else if (count==k) return root->val;
        else return kthSmallest(root->right, k);
    }
};
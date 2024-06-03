class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (root==NULL) return NULL;
        else if (root->val==target&&root->left==NULL&&root->right==NULL) return NULL;

        TreeNode *left=removeLeafNodes(root->left, target);
        TreeNode *right=removeLeafNodes(root->right, target);

        if (root->val==target&&left==NULL&&right==NULL) return NULL;
        else
        {
            root->left=left;
            root->right=right;
            return root;
        }
    }
};
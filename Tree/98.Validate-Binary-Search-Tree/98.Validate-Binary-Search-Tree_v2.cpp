class Solution {
    TreeNode *prev;
public:
    bool isValidBST(TreeNode* root) {
        if (root==NULL) return true;
        else if (isValidBST(root->left)==false) return false;
        else if (prev!=NULL&&prev->val>=root->val) return false;
        prev=root;
        if (isValidBST(root->right)==false) return false;
        else return true;
    }
};
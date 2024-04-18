class Solution {
    TreeNode *head=NULL, *prev=NULL;
public:
    TreeNode* increasingBST(TreeNode* root) {
        if (root==NULL) return head;

        increasingBST(root->left);
        if (head==NULL)
        {
            head=root;
            prev=root;
        }
        else
        {
            root->left=NULL;
            prev->right=root;
            prev=prev->right;
        }
        increasingBST(root->right);
        return head;
    }
};
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root==NULL) return 0;

        TreeNode *node=root;
        int left=0;
        while (node!=NULL)
        {
            left++;
            node=node->left;
        }
        node=root;
        int right=0;
        while (node!=NULL)
        {
            right++;
            node=node->right;
        }

        if (left==right) return pow(2, left)-1;
        else return 1+countNodes(root->left)+countNodes(root->right);
    }
};
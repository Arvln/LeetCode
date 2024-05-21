class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root==NULL) return NULL;
        else if (root->val<key)
        {
            root->right=deleteNode(root->right, key);
            return root;
        }
        else if (root->val>key)
        {
            root->left=deleteNode(root->left, key);
            return root;
        }
        else if (root->left==NULL) return root->right;
        else if (root->right==NULL) return root->left;
        else
        {
            TreeNode *node=root->right;
            while (node->left!=NULL)
                node=node->left;
            node->left=root->left;
            return root->right;
        }
    }
};
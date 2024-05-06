class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if (root==NULL) return new TreeNode(val);
        else if (root->val<val) return new TreeNode(val, root, NULL);
        else
        {
            root->right=insertIntoMaxTree(root->right, val);
            return root;
        }
    }
};
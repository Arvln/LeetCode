/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        dfs(root);
    }
    TreeNode* dfs(TreeNode* root)
    {
        if (root==NULL) return NULL;

        TreeNode* right=dfs(root->right);
        root->right=dfs(root->left);
        root->left=NULL;
        TreeNode* cur=root;
        while (cur->right!=NULL)
            cur=cur->right;
        cur->right=right;
        return root;
    }
};
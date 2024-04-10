class Solution {
    int sum=0;
public:
    int sumEvenGrandparent(TreeNode* root) {
        dfs(root, NULL, NULL);
        return sum;
    }
    void dfs(TreeNode *root, TreeNode *grandpa, TreeNode *parent)
    {
        if (root==NULL) return;
        else if (grandpa!=NULL&&grandpa->val%2==0) sum+=root->val;

        dfs(root->left, parent, root);
        dfs(root->right, parent, root);
    }
};
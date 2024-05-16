class Solution {
    vector<int>ret;
public:
    vector<int> postorderTraversal(TreeNode* root) {
        dfs(root);
        return ret;
    }
    void dfs(TreeNode *node)
    {
        if (node==NULL) return;

        dfs(node->left);
        dfs(node->right);
        ret.push_back(node->val);
    }
};
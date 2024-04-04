class Solution {
    vector<vector<int>>rets;
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        dfs(root, 0);
        reverse(rets.begin(), rets.end());
        return rets;
    }
    void dfs(TreeNode *node, int depth)
    {
        if (node==NULL) return;

        if (depth==rets.size()) rets.push_back({node->val});
        else rets[depth].push_back(node->val);

        dfs(node->left, depth+1);
        dfs(node->right, depth+1);
    }
};
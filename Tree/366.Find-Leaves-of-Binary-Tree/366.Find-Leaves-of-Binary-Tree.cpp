class Solution {
    vector<vector<int>>rets;
public:
    vector<vector<int>> findLeaves(TreeNode * root) {
        dfs(root);
        return rets;
    }
    int dfs(TreeNode *node)
    {
        if (node==NULL) return 0;

        int left=dfs(node->left);
        int right=dfs(node->right);
        int maxDepth=max(left, right);

        if (maxDepth==rets.size()) rets.push_back({node->val});
        else if (maxDepth<rets.size()) rets[maxDepth].push_back(node->val);
        return maxDepth+1;
    }
};
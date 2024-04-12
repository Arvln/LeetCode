class Solution {
    vector<vector<int>>rets;
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        dfs(root, 0);
        for (int i=0; i<rets.size(); i++)
            if (i%2==1) reverse(rets[i].begin(), rets[i].end());
        return rets;
    }
    void dfs(TreeNode *node, int depth)
    {
        if (node==NULL) return;
        else if (depth==rets.size()) rets.push_back({node->val});
        else if (depth<rets.size()) rets[depth].push_back(node->val);

        dfs(node->left, depth+1);
        dfs(node->right, depth+1);
    }
};
class Solution {
    vector<int>rets;
public:
    vector<int> largestValues(TreeNode* root) {
        dfs(root, 0);
        return rets;
    }
    void dfs(TreeNode *node, int depth)
    {
        if (node==NULL) return;
        else if (depth==rets.size()) rets.push_back(node->val);
        else if (node->val>rets[depth]) rets[depth]=node->val;

        dfs(node->left, depth+1);
        dfs(node->right, depth+1);
    }
};
class Solution {
    vector<vector<int>>rets;
public:
    vector<vector<int>> levelOrder(Node* root) {
        dfs(root, 0);
        return rets;
    }
    void dfs(Node *node, int depth)
    {
        if (node==NULL) return;
        else if (depth==rets.size()) rets.push_back({node->val});
        else if (depth<rets.size()) rets[depth].push_back(node->val);

        for (Node *child : node->children)
            dfs(child, depth+1);
    }
};
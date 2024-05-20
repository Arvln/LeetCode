class Solution {
    vector<int>rets;
public:
    vector<int> preorder(Node* root) {
        dfs(root);
        return rets;
    }
    void dfs(Node *node)
    {
        if (node==NULL) return;

        rets.push_back(node->val);
        for (Node *child : node->children)
            dfs(child);
    }
};
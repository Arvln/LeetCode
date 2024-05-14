class Solution {
    vector<int>ret;
public:
    vector<int> postorder(Node* root) {
        dfs(root);
        return ret;
    }
    void dfs(Node *node)
    {
        if (node==NULL) return;

        for (Node *child : node->children)
            dfs(child);
        ret.push_back(node->val);
    }
};
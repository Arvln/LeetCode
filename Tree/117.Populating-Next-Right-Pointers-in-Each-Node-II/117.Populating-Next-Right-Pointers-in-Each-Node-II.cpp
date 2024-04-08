class Solution {
    unordered_map<int, Node*>Map; // depth->node
public:
    Node* connect(Node* root) {
        dfs(root, 0);
        return root;
    }
    void dfs(Node *node, int depth)
    {
        if (node==NULL) return;

        if (Map.find(depth)!=Map.end()) Map[depth]->next=node;
        Map[depth]=node;

        dfs(node->left, depth+1);
        dfs(node->right, depth+1);
    }
};
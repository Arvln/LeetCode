class Solution {
    vector<Node*>level;
public:
    Node* connect(Node* root) {
        dfs(root, 0);
        return root;
    }
    void dfs(Node *node, int depth)
    {
        if (node==NULL) return;
        else if (level.size()==depth) level.push_back(node);
        else if (level.size()>depth)
        {
            level[depth]->next=node;
            level[depth]=node;
        }

        dfs(node->left, depth+1);
        dfs(node->right, depth+1);
    }
};
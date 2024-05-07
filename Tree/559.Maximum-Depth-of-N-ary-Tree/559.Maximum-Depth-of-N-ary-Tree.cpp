class Solution {
public:
    int maxDepth(Node* root) {
        if (root==NULL) return 0;
        int ret=0;
        for (Node *node : root->children)
            ret=max(ret, maxDepth(node));
        return 1+ret;
    }
};
class Solution {
public:
    Node* cloneTree(Node *root) {
        if (root==NULL) return NULL;

        Node* node=new Node(root->val);
        for (Node* child : root->children)
            node->children.push_back(cloneTree(child));
        return node;
    }
};
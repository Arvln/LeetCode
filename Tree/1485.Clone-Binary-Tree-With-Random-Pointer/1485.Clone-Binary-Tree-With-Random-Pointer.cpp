class Solution {
    unordered_map<Node*, NodeCopy*>Map;
public:
    NodeCopy* copyRandomBinaryTree(Node* root) {
        if (root==NULL) return NULL;
        if (Map.find(root)==Map.end())
            Map[root]=new NodeCopy(root->val);
        if (root->random!=NULL&&Map.find(root->random)==Map.end())
            Map[root->random]=new NodeCopy(root->random->val);

        Map[root]->left=cloneRandomTree(root->left);
        Map[root]->right=cloneRandomTree(root->right);
        Map[root]->random=Map[root->random];
        return Map[root];
    }
};
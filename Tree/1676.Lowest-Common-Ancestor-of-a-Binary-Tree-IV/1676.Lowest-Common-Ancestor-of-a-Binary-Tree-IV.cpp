class Solution {
    unordered_set<int>Set;
public:
    TreeNode* lowestCommonAncestor(TreeNode *root, vector<TreeNode*> &nodes) {
        for (TreeNode *node : nodes)
            Set.insert(node->val);
        return dfs(root);
    }
    TreeNode* dfs(TreeNode *node)
    {
        if (node==NULL) return NULL;
        else if (Set.find(node->val)!=Set.end()) return node;

        TreeNode *left=dfs(node->left);
        TreeNode *right=dfs(node->right);

        if (left==NULL) return right;
        else if (right==NULL) return left;
        else return node;
    }
};
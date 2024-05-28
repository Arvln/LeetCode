class Solution {
    unordered_set<int>Set; // deepest node val
    int maxDepth=0;
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        dfs(root, 0);
        return lca(root);
    }
    TreeNode* lca(TreeNode *node)
    {
        if (node==NULL) return NULL;
        else if (Set.find(node->val)!=Set.end()) return node;

        TreeNode *left=lca(node->left);
        TreeNode *right=lca(node->right);

        if (left==NULL) return right;
        else if (right==NULL) return left;
        else return node;
    }
    void dfs(TreeNode *node, int depth)
    {
        if (node==NULL) return;
        else if (depth>maxDepth)
        {
            maxDepth=depth;
            Set={node->val};
        }
        else if (depth==maxDepth) Set.insert(node->val);

        dfs(node->left, depth+1);
        dfs(node->right, depth+1);
    }
};
class Solution {
    vector<int>ret;
public:
    vector<int> getLonelyNodes(TreeNode *root) {
        dfs(root, NULL);
        return ret;
    }
    void dfs(TreeNode *node, TreeNode *parent)
    {
        if (node==NULL) return;

        dfs(node->left, node);
        dfs(node->right, node);

        if (parent==NULL) return;
        else if (parent->left!=NULL&&parent->right!=NULL) return;
        else ret.push_back(node->val);
    }
};
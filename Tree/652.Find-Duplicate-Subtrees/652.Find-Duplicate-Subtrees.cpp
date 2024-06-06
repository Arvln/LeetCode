class Solution {
    unordered_map<string, int>Map; // tree->count
    vector<TreeNode*>ret;
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return ret;
    }
    string dfs(TreeNode *node)
    {
        if (node==NULL) return "#";

        string symbol=to_string(node->val)+","+dfs(node->left)+","+dfs(node->right);

        if (Map[symbol]==1) ret.push_back(node);
        Map[symbol]++;

        return symbol;
    }
};
class Solution {
    vector<vector<int>>ret;
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(root, 0);
        return ret;
    }
    void dfs(TreeNode *node, int depth)
    {
        if (node==NULL) return;
        else if (ret.size()==depth) ret.push_back({node->val});
        else if (ret.size()>depth) ret[depth].push_back(node->val);

        dfs(node->left, depth+1);
        dfs(node->right, depth+1);
    }
};
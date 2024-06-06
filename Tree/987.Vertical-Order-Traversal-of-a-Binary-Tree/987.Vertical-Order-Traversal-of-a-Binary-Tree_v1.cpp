class Solution {
    map<int, vector<pair<int, int>>>Map; // col->[{depth, val}]
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);
        vector<vector<int>>rets;
        for (auto &col : Map)
        {
            sort(col.second.begin(), col.second.end());
            vector<int>ret;
            for (auto &[_, val] : col.second)
                ret.push_back(val);
            rets.push_back(ret);
        }
        return rets;
    }
    void dfs(TreeNode *node, int row, int col)
    {
        if (node==NULL) return;

        Map[col].push_back({row, node->val});
        dfs(node->left, row+1, col-1);
        dfs(node->right, row+1, col+1);
    }
};
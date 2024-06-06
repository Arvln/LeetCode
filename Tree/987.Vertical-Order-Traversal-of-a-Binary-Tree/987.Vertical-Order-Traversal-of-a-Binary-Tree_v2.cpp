class Solution {
    unordered_map<int, vector<pair<int, int>>>Map; // col->[{depth, val}]
    int minCol=0;
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);
        vector<vector<int>>rets;
        while (!Map.empty())
        {
            sort(Map[minCol].begin(), Map[minCol].end());
            vector<int>ret;
            for (auto &[_, val] : Map[minCol])
                ret.push_back(val);
            rets.push_back(ret);
            Map.erase(minCol);
            minCol++;
        }
        return rets;
    }
    void dfs(TreeNode *node, int row, int col)
    {
        if (node==NULL) return;

        Map[col].push_back({row, node->val});
        minCol=min(minCol, col);
        dfs(node->left, row+1, col-1);
        dfs(node->right, row+1, col+1);
    }
};
class Solution {
    vector<TreeNode*>memo[9][9];
public:
    vector<TreeNode*> generateTrees(int n) {
        return build(1, n);
    }
    vector<TreeNode*> build(int start, int end)
    {
        if (start>end) return {NULL};
        else if (!memo[start][end].empty()) return memo[start][end];

        vector<TreeNode*>ret;
        for (int i=start; i<=end; i++)
            for (TreeNode *left : build(start, i-1))
                for (TreeNode *right : build(i+1, end))
                    ret.push_back(new TreeNode(i, left, right));
        memo[start][end]=ret;
        return ret;
    }
};
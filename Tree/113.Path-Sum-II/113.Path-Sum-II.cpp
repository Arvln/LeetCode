class Solution {
    vector<vector<int>>ret;
    vector<int>path;
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return ret;
    }
    int dfs(TreeNode *node, int target)
    {
        if (node==NULL) return 0;
        path.push_back(node->val);
        int left=dfs(node->left, target-node->val);
        int right=dfs(node->right, target-node->val);
        int depth=max(left, right)+1;

        if (depth==1&&node->val==target) ret.push_back(path);
        path.pop_back();
        return depth;
    }
};
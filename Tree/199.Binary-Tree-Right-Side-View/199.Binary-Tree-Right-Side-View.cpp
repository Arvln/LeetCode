class Solution {
    vector<int>ret;
public:
    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0);
        return ret;
    }
    void dfs(TreeNode *node, int depth)
    {
        if (node==NULL) return;
        else if (ret.size()==depth) ret.push_back(node->val);

        dfs(node->right, depth+1);
        dfs(node->left, depth+1);
    }
};
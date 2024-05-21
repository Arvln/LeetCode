class Solution {
    int ret=0;
public:
    int longestConsecutive2(TreeNode *root) {
        dfs(root, NULL);
        return ret;
    }
    pair<int, int> dfs(TreeNode *node, TreeNode *parent)
    {
        if (node==NULL) return {0, 0};

        pair<int, int>left=dfs(node->left, node);
        pair<int, int>right=dfs(node->right, node);
        ret=max({ret, left.first+right.second+1, left.second+right.first+1});

        int up=max(left.first, right.first);
        int down=max(left.second, right.second);

        if (parent==NULL) return {0, 0};
        else if (parent->val==node->val-1) return {up+1, 0};
        else if (parent->val==node->val+1) return {0, down+1};
        else return {0, 0};
    }
};
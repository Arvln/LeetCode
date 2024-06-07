class Solution {
public:
    bool isValidSequence(TreeNode *root, vector<int> &arr) {
        return dfs(root, arr, 0);
    }
    bool dfs(TreeNode *node, vector<int> &arr, int cur)
    {
        if (node==NULL||cur>=arr.size()||node->val!=arr[cur]) return false;
        else if (cur==arr.size()-1) return node->left==NULL&&node->right==NULL;

        if (dfs(node->left, arr, cur+1)) return true;
        if (dfs(node->right, arr, cur+1)) return true;
        return false;
    }
};
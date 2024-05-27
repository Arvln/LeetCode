class Solution {
    unordered_set<int>Set; // subtree sum
public:
    bool checkEqualTree(TreeNode *root) {
        int sum=dfs(root, root);
        return sum%2==0&&Set.find(sum/2)!=Set.end();
    }
    int dfs(TreeNode *node, TreeNode *root)
    {
        if (node==NULL) return 0;

        int sum=node->val+dfs(node->left, root)+dfs(node->right, root);
        if (node!=root) Set.insert(sum);
        return sum;
    }
};
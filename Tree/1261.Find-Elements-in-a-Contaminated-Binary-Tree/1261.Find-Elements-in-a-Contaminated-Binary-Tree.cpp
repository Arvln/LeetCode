class FindElements {
    unordered_set<int>Set;
public:
    FindElements(TreeNode* root) {
        dfs(root, 0);
    }
    void dfs(TreeNode *node, int label)
    {
        if (node==NULL) return;
        Set.insert(label);

        dfs(node->left, label*2+1);
        dfs(node->right, label*2+2);
    }
    
    bool find(int target) {
        return Set.find(target)!=Set.end();
    }
};
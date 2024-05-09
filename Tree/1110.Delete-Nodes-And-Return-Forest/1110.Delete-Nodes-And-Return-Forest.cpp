class Solution {
    unordered_set<int>Set;
    vector<TreeNode*>rets;
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for (int val : to_delete)
            Set.insert(val);
        
        TreeNode *node=dfs(root);
        if (node!=NULL) rets.push_back(node);
        return rets;
    }
    TreeNode* dfs(TreeNode *node)
    {
        if (node==NULL) return NULL;
        
        TreeNode *left=dfs(node->left);
        TreeNode *right=dfs(node->right);

        if (Set.find(node->val)!=Set.end())
        {
            if (left!=NULL) rets.push_back(left);
            if (right!=NULL) rets.push_back(right);
            return NULL;
        }
        else
        {
            node->left=left;
            node->right=right;
            return node;
        }
    }
};
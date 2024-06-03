class Solution {
    unsigned int ret=0;
    vector<unsigned int>left; // depth->left most id
public:
    int widthOfBinaryTree(TreeNode* root) {
        dfs(root, 1, 0);
        return ret;
    }
    void dfs(TreeNode *node, unsigned int id, int depth)
    {
        if (node==NULL) return;
        if (left.size()==depth) left.push_back(id);
        if (left.size()>depth) ret=max(ret, id-left[depth]+1);

        dfs(node->left, id*2, depth+1);
        dfs(node->right, id*2+1, depth+1);
    }
};
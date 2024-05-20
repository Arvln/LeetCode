class Solution {
    int layer=-1;
    TreeNode *ret;
public:
    TreeNode* findNearestRightNode(TreeNode *root, TreeNode *u) {
        ret=u;
        dfs(root, u->val, 0);
        if (ret==u) return NULL;
        else return ret;
    }
    void dfs(TreeNode *node, int target, int depth)
    {
        if (node==NULL) return;

        if (node->val==target) layer=depth;
        if (layer==depth&&ret->val==target) ret=node;

        dfs(node->left, target, depth+1);
        dfs(node->right, target, depth+1);
    }
};
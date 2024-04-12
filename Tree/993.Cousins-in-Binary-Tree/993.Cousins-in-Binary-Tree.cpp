class Solution {
    int x, y;
    int xDepth, yDepth;
    int xParent, yParent;
public:
    bool isCousins(TreeNode* root, int x, int y) {
        this->x=x;
        this->y=y;
        dfs(root, -1, 0);
        return xParent!=yParent&&xDepth==yDepth;
    }
    void dfs(TreeNode *node, int parent, int depth)
    {
        if (node==NULL) return;
        else if (node->val==x)
        {
            xDepth=depth;
            xParent=parent;
        }
        else if (node->val==y)
        {
            yDepth=depth;
            yParent=parent;
        }
        
        dfs(node->left, node->val, depth+1);
        dfs(node->right, node->val, depth+1);
    }
};
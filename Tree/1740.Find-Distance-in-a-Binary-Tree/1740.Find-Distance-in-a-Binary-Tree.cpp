class Solution {
    int ret=0;
public:
    int calculateDistance(TreeNode *root, int p, int q) {
        dfs(root, p, q);
        return ret;
    }
    int dfs(TreeNode *node, int p, int q)
    {
        if (node==NULL) return -1;

        int left=dfs(node->left, p, q);
        int right=dfs(node->right, p, q);

        if (node->val==p||node->val==q)
        {
            if (left!=-1) ret=left;
            else if (right!=-1) ret=right;
            else return 1;
        }

        if (left==-1&&right==-1) return -1;
        else if (left==-1) return right+1;
        else if (right==-1) return left+1;
        else
        {
            ret=left+right;
            return -1;
        }
    }
};
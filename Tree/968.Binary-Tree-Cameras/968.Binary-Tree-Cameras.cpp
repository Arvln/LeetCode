class Solution {
    int ret=0;
public:
    int minCameraCover(TreeNode* root) {
        if (dfs(root)==0) ret++;
        return ret;
    }
    int dfs(TreeNode *node)
    {
        if (node==NULL) return 2;

        int left=dfs(node->left);
        int right=dfs(node->right);

        if (left==0||right==0)
        {
            ret++;
            return 1;
        }
        else if (left==1||right==1) return 2;
        else return 0;
    }
};
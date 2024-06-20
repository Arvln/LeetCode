class Solution {
    unordered_map<TreeNode*, int>Rob, Norob;
public:
    int rob(TreeNode* root) {
        return dfs(root, 1);
    }
    int dfs(TreeNode *node, int canRob)
    {
        if (node==NULL) return 0;
        else if (canRob==0&&Norob.find(node)!=Norob.end()) return Norob[node];
        else if (canRob==1&&Rob.find(node)!=Rob.end()) return Rob[node];

        int norob=dfs(node->left, 1)+dfs(node->right, 1);
        if (canRob==0) 
        {
            Norob[node]=norob;
            return Norob[node];
        }
        else
        {
            int rob=node->val+dfs(node->left, 0)+dfs(node->right, 0);
            Rob[node]=max(rob, norob);
            return Rob[node];
        }
    }
};
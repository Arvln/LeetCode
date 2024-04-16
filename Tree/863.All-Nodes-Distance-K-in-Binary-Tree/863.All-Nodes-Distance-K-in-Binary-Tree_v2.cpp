class Solution {
    vector<int>rets;
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root, target, k);
        return rets;
    }
    int dfs(TreeNode *node, TreeNode *target, int k)
    {
        if (node==NULL) return -1;
        else if (node->val==target->val)
        {
            pick(node, k);
            return 0;
        }
        
        int left=dfs(node->left, target, k);
        if (left!=-1)
        {
            if (left+1==k) rets.push_back(node->val);
            else pick(node->right, k-left-2);
            return left+1;
        }

        int right=dfs(node->right, target, k);
        if (right!=-1)
        {
            if (right+1==k) rets.push_back(node->val);
            else pick(node->left, k-right-2);
            return right+1;
        }
        return -1;
    }
    void pick(TreeNode *node, int depth)
    {
        if (node==NULL||depth<0) return;
        if (depth==0) rets.push_back(node->val);

        pick(node->left, depth-1);
        pick(node->right, depth-1);
    }
};
class Solution {
    vector<double>ret;
    vector<int>count;
public:
    vector<double> averageOfLevels(TreeNode* root) {
        dfs(root, 0);
        for (int i=0; i<ret.size(); i++)
            ret[i]/=count[i];
        return ret;
    }
    void dfs(TreeNode *node, int depth)
    {
        if (node==NULL) return;
        else if (ret.size()==depth)
        {
            ret.push_back(node->val);
            count.push_back(1);
        }
        else if (ret.size()>depth)
        {
            ret[depth]+=node->val;
            count[depth]++;
        }

        dfs(node->left, depth+1);
        dfs(node->right, depth+1);
    }
};
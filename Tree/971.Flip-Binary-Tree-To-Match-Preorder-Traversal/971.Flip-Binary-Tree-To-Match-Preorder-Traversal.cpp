class Solution {
    vector<int>ret;
    int i=0;
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        if (dfs(root, voyage)) return ret;
        else return {-1};
    }
    bool dfs(TreeNode *root, vector<int> &voyage)
    {
        if (root==NULL) return true;
        else if (root->val!=voyage[i]) return false;
        else if (root->left!=NULL&&root->left->val!=voyage[i+1])
        {
            ret.push_back(root->val);
            swap(root->left, root->right);
        }

        if (root->left!=NULL)
        {
            i++;
            if (dfs(root->left, voyage)==false) return false;
        }
        if (root->right!=NULL)
        {
            i++;
            if (dfs(root->right, voyage)==false) return false;
        }
        return true;
    }
};
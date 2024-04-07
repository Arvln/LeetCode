class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ret;
        if (root==NULL) return ret;

        ret.push_back(root->val);
        for (int val : preorderTraversal(root->left))
            ret.push_back(val);
        for (int val : preorderTraversal(root->right))
            ret.push_back(val);
        return ret;
    }
};
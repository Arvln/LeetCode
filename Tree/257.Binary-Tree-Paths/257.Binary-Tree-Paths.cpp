class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>rets;
        if (root==NULL) return rets;
        string ret=to_string(root->val);
        if (root->left==NULL&&root->right==NULL)
        {
            rets.push_back(ret);
            return rets;
        }

        for (string &left : binaryTreePaths(root->left))
            rets.push_back(ret+"->"+left);
        for (string &right : binaryTreePaths(root->right))
            rets.push_back(ret+"->"+right);
        return rets;
    }
};
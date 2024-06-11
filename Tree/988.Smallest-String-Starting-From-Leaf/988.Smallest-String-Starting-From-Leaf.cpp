class Solution {
    string ret, path;
public:
    string smallestFromLeaf(TreeNode* root) {
        if (root==NULL) return ret;

        path.push_back('a'+root->val);

        if (root->left==NULL&&root->right==NULL)
        {
            string curPath=path;
            reverse(curPath.begin(), curPath.end());
            if (ret.empty()||curPath<ret) ret=curPath;
        }

        smallestFromLeaf(root->left);
        smallestFromLeaf(root->right);
        path.pop_back();
        return ret;
    }
};
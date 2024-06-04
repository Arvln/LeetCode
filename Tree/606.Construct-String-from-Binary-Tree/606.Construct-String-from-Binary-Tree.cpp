class Solution {
public:
    string tree2str(TreeNode* root) {
        if (root==NULL) return "";

        string val=to_string(root->val);
        string left=tree2str(root->left);
        string right=tree2str(root->right);

        if (left.empty()&&right.empty()) return val;
        else if (left.empty()) return val+"()"+"("+right+")";
        else if (right.empty()) return val+"("+left+")";
        else return val+"("+left+")"+"("+right+")";
    }
};
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root==NULL) return subRoot==NULL;
        else if (isSubtree(root->left, subRoot)) return true;
        else if (isSubtree(root->right, subRoot)) return true;
        else return isSame(root, subRoot);
    }
    bool isSame(TreeNode *p, TreeNode *q)
    {
        if (p==NULL) return q==NULL;
        else if (q==NULL) return false;
        else if (isSame(p->left, q->left)==false) return false;
        else if (isSame(p->right, q->right)==false) return false;
        else return p->val==q->val;
    }
};
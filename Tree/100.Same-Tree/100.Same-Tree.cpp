class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p==NULL) return q==NULL;
        else if (q==NULL) return false;
        else return p->val==q->val&&isSameTree(p->left, q->left)&&isSameTree(p->right, q->right);
    }
};
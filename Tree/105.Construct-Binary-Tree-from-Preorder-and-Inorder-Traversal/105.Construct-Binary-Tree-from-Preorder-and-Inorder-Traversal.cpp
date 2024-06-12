class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
    TreeNode* build(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd)
    {
        if (preStart>preEnd) return NULL;

        int val=preorder[preStart];
        int i=inStart;
        while (i<=inEnd&&inorder[i]!=val)
            i++;
        return new TreeNode(
            val,
            build(preorder, preStart+1, preStart+i-inStart, inorder, inStart, i-1),
            build(preorder, preStart+i-inStart+1, preEnd, inorder, i+1, inEnd)
        );
    }
};
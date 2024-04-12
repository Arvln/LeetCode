class Solution {
    vector<int>inorder, postorder;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        this->inorder=inorder;
        this->postorder=postorder;
        return build(0, inorder.size()-1, 0, postorder.size()-1);
    }
    TreeNode* build(int inStart, int inEnd, int postStart, int postEnd)
    {
        if (postStart>postEnd) return NULL;
        int val=postorder[postEnd];
        if (postStart==postEnd) return new TreeNode(val);

        int j=inStart;
        while (j<inEnd&&inorder[j]!=val) j++;
        int leftSize=j-inStart;
        return new TreeNode(
            val,
            build(inStart, j-1, postStart, postStart+leftSize-1),
            build(j+1, inEnd, postStart+leftSize, postEnd-1)
        );
    }
};
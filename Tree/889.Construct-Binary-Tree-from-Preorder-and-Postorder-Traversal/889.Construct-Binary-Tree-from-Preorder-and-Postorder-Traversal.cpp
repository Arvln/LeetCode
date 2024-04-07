class Solution {
    vector<int>preorder, postorder;
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        this->preorder=preorder;
        this->postorder=postorder;
        return build(0, preorder.size()-1, 0, postorder.size()-1);
    }
    TreeNode* build(int preStart, int preEnd, int postStart, int postEnd)
    {
        if (preStart>preEnd) return NULL;
        int val=preorder[preStart];
        if (preStart==preEnd) return new TreeNode(val);

        int j=postStart;
        while (j<postEnd&&postorder[j]!=preorder[preStart+1]) j++;
        int leftSize=j-postStart+1;
        
        return new TreeNode(
            val,
            build(preStart+1, preStart+leftSize, postStart, postStart+leftSize-1),
            build(preStart+leftSize+1, preEnd, postStart+leftSize, postEnd)
        );
    }
};
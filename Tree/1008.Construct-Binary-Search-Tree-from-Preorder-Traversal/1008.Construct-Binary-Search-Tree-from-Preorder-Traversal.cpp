class Solution {
    vector<int>preorder;
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        this->preorder=preorder;
        return build(0, preorder.size()-1);
    }
    TreeNode* build(int start, int end)
    {
        if (start>end) return NULL;

        int val=preorder[start];
        int j=start+1;
        while (j<=end&&preorder[j]<val) j++;
        return new TreeNode(val, build(start+1, j-1), build(j, end));
    }
};
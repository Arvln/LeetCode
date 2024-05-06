class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size()-1);
    }
    TreeNode* build(vector<int> &nums, int start, int end)
    {
        if (start>end) return NULL;

        auto iter=max_element(nums.begin()+start, nums.begin()+end+1);
        return new TreeNode(
            *iter,
            build(nums, start, iter-nums.begin()-1),
            build(nums, iter-nums.begin()+1, end)
        );
    }
};
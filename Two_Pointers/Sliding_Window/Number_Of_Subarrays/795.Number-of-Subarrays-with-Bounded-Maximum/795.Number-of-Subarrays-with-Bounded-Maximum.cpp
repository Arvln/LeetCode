class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return at_most_k(nums, right)-at_most_k(nums, left-1);
    }
    int at_most_k(vector<int>& nums, int k)
    {
        int left=0, right=0, ret=0;
        while (right<nums.size())
        {
            right++;
            if (nums[right-1]>k)
                left=right;
            ret+=right-left;
        }
        return ret;
    }
};
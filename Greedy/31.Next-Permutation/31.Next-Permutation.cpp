class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=nums.size()-1;
        while (i-1>=0&&nums[i-1]>=nums[i])
            i--;
        reverse(nums.begin()+i, nums.end());

        if (i-1>=0)
        {
            auto iter=upper_bound(nums.begin()+i, nums.end(), nums[i-1]);
            swap(nums[i-1], *iter);
        }
    }
};
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int s=0;
        for (int f=s; f<n; f++)
            if (nums[f]==0)
            {
                swap(nums[s], nums[f]);
                s++;
            }
        for (int f=s; f<n; f++)
            if (nums[f]==1)
            {
                swap(nums[s], nums[f]);
                s++;
            }
    }
};
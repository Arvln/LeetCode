class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int s=0;
        for (int f=0; f<nums.size(); f++)
        {
            if (nums[s]!=nums[f])
            {
                s++;
                nums[s]=nums[f];
            }
        }
        return s+1;
    }
};
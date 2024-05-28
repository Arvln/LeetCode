class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int s=0;
        for (int f=0; f<nums.size(); f++)
            if (nums[f]!=val)
            {
                nums[s]=nums[f];
                s++;
            }
        return s;
    }
};
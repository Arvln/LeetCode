class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int s=0;
        for (int f=0; f<nums.size(); f++)
        {
            int f0=f;
            while (f+1<nums.size()&&nums[f]==nums[f+1])
                f++;
            
            for (int len=min(2, f-f0+1); len>0; len--)
            {
                nums[s]=nums[f];
                s++;
            }
        }
        return s;
    }
};
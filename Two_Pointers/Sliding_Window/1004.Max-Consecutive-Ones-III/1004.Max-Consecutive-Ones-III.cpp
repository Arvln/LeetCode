class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0, r=0, ret=0;
        while (r<nums.size())
        {
            if (nums[r]==0) k--;
            r++;

            while (k<0)
            {
                if (nums[l]==0) k++;
                l++;
            }
            ret=max(ret, r-l);
        }
        return ret;
    }
};
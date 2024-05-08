class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int l=0, r=0, ret=0, count0=0;
        while (r<nums.size())
        {
            count0+=nums[r]==0;
            r++;

            while (l<r&&count0>1)
            {
                count0-=nums[l]==0;
                l++;
            }
            ret=max(ret, r-l);
        }
        return ret;
    }
};
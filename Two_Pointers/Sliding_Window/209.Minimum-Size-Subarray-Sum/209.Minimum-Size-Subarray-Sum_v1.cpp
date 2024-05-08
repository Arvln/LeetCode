class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0, r=0, sum=0, ret=INT_MAX;
        while (r<nums.size())
        {
            sum+=nums[r];
            r++;

            while (l<r&&sum>=target)
            {
                ret=min(ret, r-l);
                sum-=nums[l];
                l++;
            }
        }
        
        if (ret==INT_MAX) return 0;
        else return ret;
    }
};
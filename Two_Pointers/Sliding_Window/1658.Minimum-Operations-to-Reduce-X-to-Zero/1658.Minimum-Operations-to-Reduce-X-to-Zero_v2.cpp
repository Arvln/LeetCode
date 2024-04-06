class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total=accumulate(nums.begin(), nums.end(), 0);
        int l=0, r=0, sum=0, len=INT_MIN;
        while (r<nums.size())
        {
            sum+=nums[r];
            r++;

            while (l<r&&total-sum<x)
            {
                sum-=nums[l];
                l++;
            }

            if (total-sum==x)
                len=max(len, r-l);
        }

        if (len==INT_MIN) return -1;
        else return nums.size()-len;
    }
};
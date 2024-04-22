class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0, r=nums.size();
        int ret=INT_MAX;
        while (l<r)
        {
            int mid=l+(r-l)/2;

            if (nums[l]<nums[mid])
            {
                ret=min(ret, nums[l]);
                l=mid+1;
            }
            else
            {
                ret=min(ret, nums[mid]);
                r=mid;
            }
        }
        return ret;
    }
};
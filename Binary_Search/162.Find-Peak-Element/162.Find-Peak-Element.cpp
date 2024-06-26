class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0, r=nums.size()-1;
        while (l<=r)
        {
            int mid=l+(r-l)/2;

            if ((mid==0||nums[mid-1]<nums[mid])&&(mid==nums.size()-1||nums[mid]>nums[mid+1])) return mid;
            else if (mid==0||nums[mid-1]<nums[mid]) l=mid+1;
            else r=mid-1;
        }
        return -1;
    }
};
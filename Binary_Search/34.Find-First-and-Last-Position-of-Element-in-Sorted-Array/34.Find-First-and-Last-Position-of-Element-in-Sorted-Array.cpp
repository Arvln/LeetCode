class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ret{-1, -1};
        int l=0, r=nums.size();
        while (l<r)
        {
            int mid=l+(r-l)/2;

            if (nums[mid]<target) l=mid+1;
            else r=mid;
        }
        if (l<nums.size()&&nums[l]==target) ret[0]=l;
        l=0, r=nums.size();
        while (l<r)
        {
            int mid=l+(r-l)/2;

            if (nums[mid]<=target) l=mid+1;
            else r=mid;
        }
        if (l-1<nums.size()&&nums[l-1]==target) ret[1]=l-1;
        return ret;
    }
};
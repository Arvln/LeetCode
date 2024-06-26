class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;
        while (l<=r)
        {
            int mid=l+(r-l)/2;

            if (nums[mid]==target) return true;
            else if (l+1<nums.size()&&nums[l]==nums[l+1]) l++;
            else if (r-1>=0&&nums[r-1]==nums[r]) r--;
            else if (nums[l]<=nums[mid])
            {
                if (target<nums[mid]&&target>=nums[l]) r=mid-1;
                else l=mid+1;
            }
            else
            {
                if (target>nums[mid]&&target<=nums[r]) l=mid+1;
                else r=mid-1;
            }
        }
        return false;
    }
};
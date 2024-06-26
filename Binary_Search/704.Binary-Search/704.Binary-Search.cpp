class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, r=nums.size();

        while (l<r)
        {
            int mid=l+(r-l)/2;

            if (nums[mid]==target) return mid;
            else if (nums[mid]<target) l=mid+1;
            else r=mid;
        }
        return -1;
    }
};
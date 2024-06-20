class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l=-1e4, r=1e4;
        while (l<=r)
        {
            int mid=l+(r-l)/2;

            if (count(nums, mid)<k) r=mid-1;
            else l=mid+1;
        }
        return r;
    }
    int count(vector<int> &nums, int t)
    {
        int ret=0;
        for (int num : nums)
            ret+=num>=t;
        return ret;
    }
};
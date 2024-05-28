class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l=0, r=INT_MAX;
        while (l<=r)
        {
            int mid=l+(r-l)/2;

            if (count(nums, mid)>k) l=mid+1;
            else r=mid-1; 
        }
        return l;
    }
    int count(vector<int> &nums, int limit)
    {
        int ret=0, sum=0;
        for (int num : nums)
        {
            if (num>limit) return INT_MAX;

            sum-=num;
            if (sum<0)
            {
                sum=limit-num;
                ret++;
            }
        }
        return ret;
    }
};
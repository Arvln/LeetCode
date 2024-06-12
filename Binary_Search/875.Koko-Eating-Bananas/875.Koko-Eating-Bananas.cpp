class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1, r=INT_MAX;
        while (l<=r)
        {
            int mid=l+(r-l)/2;

            if (count(piles, mid)>h) l=mid+1;
            else r=mid-1;
        }
        return l;
    }
    int count(vector<int> &nums, int t)
    {
        int ret=0;
        for (int num : nums)
            ret+=num/t+(num%t>0);
        return ret;
    }
};
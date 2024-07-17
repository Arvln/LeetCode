class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int l=1, r=nums.size();
        while (l<=r)
        {
            int mid=l+(r-l)/2;

            if (isSpecial(nums, mid, k)) r=mid-1;
            else l=mid+1;
        }

        if (isSpecial(nums, l, k)) return l;
        else return -1;
    }
    bool isSpecial(vector<int> &nums, int len, int k)
    {
        vector<int>count(32);
        int l=0, r=0, val=0;
        while (r<nums.size())
        {
            for (int i=0; i<32; i++)
                count[i]+=(nums[r]>>i)&1;
            r++;

            if (l<r&&r-l>len)
            {
                for (int i=0; i<32; i++)
                    count[i]-=(nums[l]>>i)&1;
                l++;
            }

            int sum=0;
            for (int i=0; i<32; i++)
                if (count[i]>0) sum|=1<<i;
            if (r-l==len&&sum>=k) return true;
        }
        return false;
    }
};
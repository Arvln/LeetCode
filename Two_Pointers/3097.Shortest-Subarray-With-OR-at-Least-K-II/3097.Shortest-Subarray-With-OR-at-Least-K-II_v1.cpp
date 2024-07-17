class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int>count(32, 0);
        int l=0, r=0, val=0, ret=INT_MAX;
        while (r<nums.size())
        {
            for (int i=0; i<32; i++)
                count[i]+=(nums[r]>>i)&1;
            val|=nums[r];
            r++;

            while (l<r&&val>=k)
            {
                ret=min(ret, r-l);
                
                for (int i=0; i<32; i++)
                    count[i]-=(nums[l]>>i)&1;

                int sum=0;
                for (int i=0; i<32; i++)
                    if (count[i]>0) sum+=1<<i;
                val=sum;
                l++;
            }
        }

        if (ret==INT_MAX) return -1;
        else return ret;
    }
};
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int left=0, right=0, count=0;
        long long ret=0, sum=0;
        vector<int> records(100001, 0);
        while (right<nums.size())
        {
            if (records[nums[right]]==0)
                count+=1;

            sum+=nums[right];
            records[nums[right]]+=1;
            right++;

            if (left<right&&right-left==k)
            {
                if (count==k)
                    ret=max(ret, sum);
                if (records[nums[left]]==1)
                    count-=1;

                sum-=nums[left];
                records[nums[left]]-=1;
                left++;
            }
        }
        return ret;
    }
};
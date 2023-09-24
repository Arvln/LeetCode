class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return at_most_k(nums, k)-at_most_k(nums, k-1);
    }
    int at_most_k(vector<int>& nums, int k)
    {
        int left=0, right=0, ret=0, n=nums.size();
        vector<int> records(n+1, 0);
        while (right<n)
        {
            if (records[nums[right]]==0) k-=1;
            records[nums[right]]+=1;
            right++;

            while (left<right&&k<0)
            {
                if (records[nums[left]]==1) k++;
                records[nums[left]]-=1;
                left++;
            }
            ret+=right-left;
        }
        return ret;
    }
};
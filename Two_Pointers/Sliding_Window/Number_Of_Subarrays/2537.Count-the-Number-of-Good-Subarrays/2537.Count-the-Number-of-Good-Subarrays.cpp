class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n=nums.size();
        return (long)(n+1)*n/2-at_most_k(nums, k-1);
    }
    long long at_most_k(vector<int>& nums, int k)
    {
        int left=0, right=0;
        long long ret=0;
        unordered_map<int, int> records;
        while (right<nums.size())
        {
            k-=records[nums[right]];
            records[nums[right]]+=1;
            right++;

            while (left<right&&k<0)
            {
                records[nums[left]]-=1;
                k+=records[nums[left]];
                left++;
            }
            ret+=right-left;
        }
        return ret;
    }
};
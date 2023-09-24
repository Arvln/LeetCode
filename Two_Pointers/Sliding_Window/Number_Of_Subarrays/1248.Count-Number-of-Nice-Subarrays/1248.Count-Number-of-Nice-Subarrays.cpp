class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return at_most_k(nums, k)-at_most_k(nums, k-1);
    }
    int at_most_k(vector<int>& nums, int k)
    {
        int left=0, right=0, ret=0;
        while (right<nums.size())
        {
            if (nums[right]&1) k-=1;
            right++;

            while (left<right&&k<0)
            {
                if (nums[left]&1) k+=1;
                left++;
            }
            ret+=right-left;
        }
        return ret;
    }
};
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left=0, right=0, product=1, ret=0;
        while (right<nums.size())
        {
            product*=nums[right];
            right++;

            while (left<right&&product>=k)
            {
                product/=nums[left];
                left++;
            }
            ret+=right-left;
        }
        return ret;
    }
};
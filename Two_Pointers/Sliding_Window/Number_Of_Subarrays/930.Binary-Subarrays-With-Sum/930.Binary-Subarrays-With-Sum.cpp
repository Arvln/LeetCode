class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        if (goal==0) return at_most_k(nums, goal);
        return at_most_k(nums, goal)-at_most_k(nums, goal-1);
    }
    int at_most_k(vector<int>& nums, int goal)
    {
        int left=0, right=0, ret=0;
        while (right<nums.size())
        {
            goal-=nums[right];
            right++;

            while (left<right&&goal<0)
            {
                goal+=nums[left];
                left++;
            }
            ret+=right-left;
        }
        return ret;
    }
};
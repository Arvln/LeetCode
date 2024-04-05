class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxS=0, minS=0, maxSum=INT_MIN, minSum=INT_MAX;
        for (int num : nums)
        {
            maxS=max(maxS+num, num);
            minS=min(minS+num, num);
            maxSum=max(maxSum, maxS);
            minSum=min(minSum, minS);
        }
        int total=accumulate(nums.begin(), nums.end(), 0);
        if (total==minSum) return maxSum;
        else return max(maxSum, total-minSum);
    }
};
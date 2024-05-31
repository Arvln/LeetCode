class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxSum=1, minSum=1, ret=INT_MIN;
        for (int num : nums)
        {
            int preMax=maxSum, preMin=minSum;
            maxSum=max({num, preMax*num, preMin*num});
            minSum=min({num, preMax*num, preMin*num});
            ret=max(ret, maxSum);
        }
        return ret;
    }
};
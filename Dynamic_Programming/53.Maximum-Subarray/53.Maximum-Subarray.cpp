class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0, ret=INT_MIN;
        for (int num : nums)
        {
            sum=max(sum+num, num);
            ret=max(ret, sum);
        }
        return ret;
    }
};
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(), 0);
        vector<int>dp(n+1, 0);

        int ret=0;
        for (int i=1; i<=n; i++)
        {
            if (nums[i]==1) dp[i]=dp[i-1]+1;
            ret=max(ret, dp[i]);
        }
        return ret;
    }
};
class Solution {
public:
    int splitArray(vector<int>& nums, int K) {
        int n=nums.size();
        nums.insert(nums.begin(), 0);
        vector<vector<int>>dp(n+1, vector<int>(K+1, INT_MAX));
        dp[0][0]=0;

        for (int i=1; i<=n; i++)
            for (int k=1; k<=min(i, K); k++)
            {
                int sum=0;
                for (int j=i; j>=k; j--)
                {
                    sum+=nums[j];
                    dp[i][k]=min(dp[i][k], max(dp[j-1][k-1], sum));
                }
            }
        return dp[n][K];
    }
};
class Solution {
public:
    int splitArray(vector<int>& nums, int K) {
        int n=nums.size();
        nums.insert(nums.begin(), 0);
        vector<vector<int>> dp(n+1, vector<int>(K+1, INT_MAX));

        dp[0][0]=0;
        dp[0][1]=0;
        for (int i=1; i<=n; i++)
            dp[i][1]=dp[i-1][1]+nums[i];
        for (int i=1; i<=n; i++)
            for (int k=1; k<=min(i, K); k++)
                for (int j=k; j<=i; j++)
                    dp[i][k]=min(dp[i][k], max(dp[j-1][k-1], dp[i][1]-dp[j-1][1]));
        
        return dp[n][K];
    }
};
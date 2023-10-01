class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int K) {
        int n=nums.size();
        nums.insert(nums.begin(), 0);
        vector<vector<double>> dp(n+1, vector<double>(K+1, INT_MIN));
        vector<double> prefix_sum(n+1, 0);
        for (int i=1; i<=n; i++)
            prefix_sum[i]=prefix_sum[i-1]+nums[i];
        dp[0][0]=0;
        for (int i=1; i<=n; i++)
            for (int k=1; k<=min(i, K); k++)
                for (int j=k; j<=i; j++)
                    dp[i][k]=max(dp[i][k], dp[j-1][k-1]+(prefix_sum[i]-prefix_sum[j-1])/(i-j+1));
        
        return dp[n][K];
    }
};
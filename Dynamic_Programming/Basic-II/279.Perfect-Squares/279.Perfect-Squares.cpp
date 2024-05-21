class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n+1, INT_MAX/2);
        dp[0]=0;
        for (int sum=1; sum<=n; sum++)
            for (int i=1; i*i<=sum; i++)
                dp[sum]=min(dp[sum], dp[sum-i*i]+1);
        return dp[n];
    }
};
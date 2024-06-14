class Solution {
public:
    int maxA(int n) {
        vector<int>dp(n+1, 0);
        for (int i=1; i<=n; i++)
        {
            dp[i]=dp[i-1]+1;
            for (int j=1; i-2-j>0; j++)
                dp[i]=max(dp[i], dp[i-2-j]*(j+1));
        }
        return dp[n];
    }
};
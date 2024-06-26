class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>>dp(n+2, vector<int>(n+2, 0));
        for (int i=1; i<=n; i++)
            dp[i][i]=0;

        for (int len=2; len<=n; len++)
            for (int i=1, j=i+len-1; j<=n; i++, j++)
            {
                dp[i][j]=INT_MAX;
                for (int k=i; k<=j; k++)
                    dp[i][j]=min(dp[i][j], k+max(dp[i][k-1], dp[k+1][j]));
            }
        return dp[1][n];
    }
};
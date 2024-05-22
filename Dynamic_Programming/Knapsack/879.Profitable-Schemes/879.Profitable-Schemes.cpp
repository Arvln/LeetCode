class Solution {
    int dp[105][105][105];
    int M=1e9+7;
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int N=group.size();
        group.insert(group.begin(), 0);
        profit.insert(profit.begin(), 0);

        dp[0][0][0]=1;
        for (int i=1; i<=N; i++)
            for (int j=0; j<=n; j++)
                for (int k=0; k<=minProfit; k++)
                {
                    int x=group[i], y=profit[i];

                    dp[i][j][k]+=dp[i-1][j][k];
                    dp[i][j][k]%=M;

                    if (j+x<=n)
                    {
                        dp[i][j+x][min(k+y, minProfit)]+=dp[i-1][j][k];
                        dp[i][j+x][min(k+y, minProfit)]%=M;
                    }
                }
        
        int ret=0;
        for (int i=0; i<=n; i++)
            ret=(ret+dp[N][i][minProfit])%M;
        return ret;
    }
};
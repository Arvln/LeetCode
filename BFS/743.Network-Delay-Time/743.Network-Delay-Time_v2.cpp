class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int K) {
        vector<vector<int>>dp(n+1, vector<int>(n+1, INT_MAX/2));

        for (auto &time : times)
            dp[time[0]][time[1]]=time[2];
        for (int i=1; i<=n; i++)
            dp[i][i]=0;
        
        for (int k=1; k<=n; k++)
            for (int i=1; i<=n; i++)
                for (int j=1; j<=n; j++)
                    dp[i][j]=min(dp[i][j], dp[i][k]+dp[k][j]);
        
        int ret=0;
        for (int i=1; i<=n; i++)
        {
            if (dp[K][i]==INT_MAX/2) return -1;
            ret=max(ret, dp[K][i]);
        }
        return ret;
    }
};
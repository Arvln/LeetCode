class Solution {
    int dp[6][7][7][243];
    int temp1[5], temp2[5];
    int n;
public:
    int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
        int N=pow(3, n);
        this->n=n;
        for (int row=0; row<=m; row++)
            for (int i=0; i<=introvertsCount; i++)
                for (int j=0; j<=extrovertsCount; j++)
                    for (int state=0; state<N; state++)
                        dp[row][i][j][state]=INT_MIN/2;
        
        dp[0][0][0][0]=0;
        int ret=0;
        for (int row=1; row<=m; row++)
            for (int i=0; i<=introvertsCount; i++)
                for (int j=0; j<=extrovertsCount; j++)
                    for (int cur=0; cur<N; cur++)
                    {
                        auto [x, y]=count(cur);
                        if (i<x||j<y) continue;

                        for (int pre=0; pre<N; pre++)
                        {
                            dp[row][i][j][cur]=max(dp[row][i][j][cur], dp[row-1][i-x][j-y][pre]+happiness(cur, pre));
                        }
                        if (row==m) ret=max(ret, dp[m][i][j][cur]);
                    }
        return ret;
    }
    int increment(int self, int neighbor)
    {
        if (neighbor==0) return 0;
        else if (self==1) return -30;
        else if (self==2) return 20;
        else return 0;
    }
    int happiness(int cur, int pre)
    {
        for (int i=0; i<n; i++)
        {
            temp1[i]=cur%3;
            temp2[i]=pre%3;
            cur/=3;
            pre/=3;
        }

        int ret=0;
        for (int i=0; i<n; i++)
        {
            if (temp1[i]==0) continue;

            ret+=(temp1[i]==1)*120;
            ret+=(temp1[i]==2)*40;

            if (i>0) ret+=increment(temp1[i], temp1[i-1]);
            if (i<n-1) ret+=increment(temp1[i], temp1[i+1]);

            ret+=increment(temp1[i], temp2[i]);
            ret+=increment(temp2[i], temp1[i]);
        }
        return ret;
    }
    pair<int, int> count(int p)
    {
        int intro=0, extro=0;
        for (int i=0; i<n; i++)
        {
            intro+=(p%3)==1;
            extro+=(p%3)==2;
            p/=3;
        }
        return {intro, extro};
    }
};
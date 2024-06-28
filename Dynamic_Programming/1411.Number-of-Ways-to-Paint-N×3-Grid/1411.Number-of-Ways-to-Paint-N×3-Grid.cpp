class Solution {
    int temp1[3], temp2[3];
    int M=1e9+7;
public:
    int numOfWays(int n) {
        vector<int>dp(27, 0);
        for (int p=0; p<27; p++)
            if (rowValid(p)) dp[p]=1;

        for (int i=1; i<n; i++)
        {
            auto pre_dp=dp;
            for (int cur=0; cur<27; cur++)
            {
                if (rowValid(cur)==false) continue;
                dp[cur]=0;
                for (int pre=0; pre<27; pre++)
                {
                    if (rowValid(pre)==false) continue;
                    if (crossValid(cur, pre)==false) continue;

                    dp[cur]=(dp[cur]+pre_dp[pre])%M;
                }
            }
        }

        int ret=0;
        for (int p=0; p<27; p++)
            if (rowValid(p)) ret=(ret+dp[p])%M;
        return ret;
    }
    bool crossValid(int cur, int pre)
    {
        for (int i=0; i<3; i++)
        {
            temp1[i]=cur%3;
            temp2[i]=pre%3;
            cur/=3;
            pre/=3;
        }
        return temp1[0]!=temp2[0]&&temp1[1]!=temp2[1]&&temp1[2]!=temp2[2];
    }
    bool rowValid(int p)
    {
        for (int i=0; i<3; i++)
        {
            temp1[i]=p%3;
            p/=3;
        }
        return temp1[0]!=temp1[1]&&temp1[1]!=temp1[2];
    }
};
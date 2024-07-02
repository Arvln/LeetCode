class Solution {
    int temp1[5], temp2[5];
    int m;
public:
    int colorTheGrid(int m, int n) {
        this->m=m;
        int M=pow(3, m);
        int mod=1e9+7;
        vector<int>dp(M, 0);
        for (int state=0; state<M; state++)
            if (colValid(state)) dp[state]=1;

        for (int col=1; col<n; col++)
        {
            auto pre_dp=dp;
            for (int state=0; state<M; state++)
            {
                if (colValid(state)==false) continue;
                dp[state]=0;
                for (int pre=0; pre<M; pre++)
                {
                    if (colValid(pre)==false) continue;
                    if (crossValid(state, pre)==false) continue;

                    dp[state]=(dp[state]+pre_dp[pre])%mod;
                }
            }
        }

        int ret=0;
        for (int state=0; state<M; state++)
            if (colValid(state)) ret=(ret+dp[state])%mod;
        return ret;
    }
    bool crossValid(int state, int pre)
    {
        for (int i=0; i<m; i++)
        {
            temp1[i]=state%3;
            temp2[i]=pre%3;
            state/=3;
            pre/=3;
        }
        for (int i=0; i<m; i++)
            if (temp1[i]==temp2[i]) return false;
        return true;
    }
    bool colValid(int p)
    {
        for (int i=0; i<m; i++)
        {
            temp1[i]=p%3;
            p/=3;
        }
        for (int i=1; i<m; i++)
            if (temp1[i]==temp1[i-1]) return false;
        return true;
    }
};
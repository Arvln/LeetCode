class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n=jobs.size();
        int N=1<<n;
        vector<int>times(N);
        for (int status=1; status<N; status++)
        {
            int sum=0;
            for (int i=0; i<n; i++)
                sum+=((status>>i)&1)*jobs[i];
            times[status]=sum;
        }
        vector<int>dp(N, INT_MAX/2);
        dp[0]=0;

        for (int i=1; i<=k; i++)
        {
            auto pre_dp=dp;
            for (int status=0; status<N; status++)
                for (int subset=status; subset>0; subset=(subset-1)&status)
                    dp[status]=min(dp[status], max(pre_dp[status-subset], times[subset]));
        }
        return dp[N-1];
    }
};
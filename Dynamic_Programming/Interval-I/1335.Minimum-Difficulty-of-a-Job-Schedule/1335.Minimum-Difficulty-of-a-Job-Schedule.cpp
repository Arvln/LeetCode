class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        if (n<d) return -1;

        jobDifficulty.insert(jobDifficulty.begin(), 0);
        vector<vector<int>>dp(n+1, vector<int>(d+1, INT_MAX/2));
        dp[0][0]=0;

        for (int i=1; i<=n; i++)
            for (int k=1; k<=min(i, d); k++)
            {
                int diff=0;
                for (int j=i; j>=k; j--)
                {
                    diff=max(diff, jobDifficulty[j]);
                    dp[i][k]=min(dp[i][k], dp[j-1][k-1]+diff);
                }
            }
        return dp[n][d];
    }
};
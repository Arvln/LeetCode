class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        days.insert(days.begin(), 0);
        vector<int>dp(n+1, INT_MAX/2);
        dp[0]=0;

        for (int i=1; i<=n; i++)
            for (int j=i; j>0; j--)
            {
                int diff=days[i]-days[j];

                if (diff<1) dp[i]=min(dp[i], dp[j-1]+costs[0]);
                if (diff<7) dp[i]=min(dp[i], dp[j-1]+costs[1]);
                if (diff<30) dp[i]=min(dp[i], dp[j-1]+costs[2]);
            }
        return dp[n];
    }
};
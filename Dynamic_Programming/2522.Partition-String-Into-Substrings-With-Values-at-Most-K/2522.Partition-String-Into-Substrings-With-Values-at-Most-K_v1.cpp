class Solution {
public:
    int minimumPartition(string s, int k) {
        int n=s.size();
        s="#"+s;
        vector<int>dp(n+1, INT_MAX/2);
        dp[0]=0;

        for (int i=1; i<=n; i++)
            for (int j=i; j>=1; j--)
            {
                long num=stol(s.substr(j, i-j+1));
                if (num>k) break;

                dp[i]=min(dp[i], dp[j-1]+1);
            }

        if (dp[n]==INT_MAX/2) return -1;
        else return dp[n];
    }
};
class Solution {
public:
    int minInsertions(string s) {
        string t=s;
        reverse(t.begin(), t.end());

        int n=s.size();
        s="#"+s;
        t="#"+t;
        vector<vector<int>>dp(n+1, vector<int>(n+1, INT_MIN/2));
        for (int i=0; i<=n; i++)
        {
            dp[i][0]=0;
            dp[0][i]=0;
        }

        for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++)
                if (s[i]==t[j]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
        return n-dp[n][n];
    }
};
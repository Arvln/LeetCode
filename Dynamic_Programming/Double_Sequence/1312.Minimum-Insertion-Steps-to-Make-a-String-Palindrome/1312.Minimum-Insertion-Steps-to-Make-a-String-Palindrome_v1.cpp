class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        vector<vector<int>>dp(n, vector<int>(n));
        for (int i=0; i<n; i++)
            dp[i][i]=0;
        for (int i=0; i+1<n; i++)
            dp[i][i+1]=s[i]!=s[i+1];

        for (int len=3; len<=n; len++)
            for (int i=0, j=i+len-1; j<n; i++, j++)
                if (s[i]==s[j]) dp[i][j]=dp[i+1][j-1];
                else dp[i][j]=min(dp[i][j-1], dp[i+1][j])+1;
        return dp[0][n-1];
    }
};
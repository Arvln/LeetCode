class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>>dp(n, vector<int>(n, INT_MIN/2));
        for (int i=0; i<n; i++)
            dp[i][i]=1;
        for (int i=0; i+1<n; i++)
            dp[i][i+1]=1+(s[i]==s[i+1]);

        for (int len=3; len<=n; len++)
            for (int i=0, j=i+len-1; j<n; i++, j++)
                if (s[i]==s[j]) dp[i][j]=dp[i+1][j-1]+2;
                else dp[i][j]=max(dp[i][j-1], dp[i+1][j]);
        return dp[0][n-1];
    }
};
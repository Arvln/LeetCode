class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n=s.size();
        s="#"+s;
        vector<int>dp(n+1, 0);

        vector<vector<int>>isPalin(n+1, vector<int>(n+1, 0));
        for (int i=1; i<=n; i++)
        {
            isPalin[i][i]=1;
            if (i+1<=n&&s[i]==s[i+1]) isPalin[i][i+1]=1;
        }
        for (int len=3; len<=n; len++)
            for (int i=1, j=i+len-1; j<=n; i++, j++)
                if (s[i]==s[j]) isPalin[i][j]=isPalin[i+1][j-1];

        for (int i=1; i<=n; i++)
        {
            dp[i]=max(dp[i], dp[i-1]);
            for (int j=1; j<=i-k+1; j++)
                if (isPalin[j][i]) dp[i]=max(dp[i], dp[j-1]+1);
        }
        return dp[n];
    }
};
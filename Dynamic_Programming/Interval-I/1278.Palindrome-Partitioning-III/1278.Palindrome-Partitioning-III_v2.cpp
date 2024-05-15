class Solution {
public:
    int palindromePartition(string s, int K) {
        int n=s.size();
        s="#"+s;

        vector<vector<int>>count(n+1, vector<int>(n+1, 0));
        for (int i=1; i+1<=n; i++)
            count[i][i+1]=s[i]!=s[i+1];
        for (int len=3; len<=n; len++)
            for (int i=1, j=i+len-1; j<=n; i++, j++)
                if (s[i]==s[j]) count[i][j]=count[i+1][j-1];
                else count[i][j]=count[i+1][j-1]+1;

        vector<vector<int>>dp(n+1, vector<int>(K+1, INT_MAX/2));
        dp[0][0]=0;
        for (int i=1; i<=n; i++)
            for (int k=1; k<=min(i, K); k++)
                for (int j=i; j>=k; j--)
                    dp[i][k]=min(dp[i][k], dp[j-1][k-1]+count[j][i]);
        return dp[n][K];
    }
};
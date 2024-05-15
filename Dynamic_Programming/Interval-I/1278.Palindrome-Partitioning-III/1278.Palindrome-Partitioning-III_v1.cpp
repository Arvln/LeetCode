class Solution {
public:
    int palindromePartition(string s, int K) {
        int n=s.size();
        s="#"+s;
        vector<vector<int>> dp(n+1, vector<int>(K+1, INT_MAX/2));
        dp[0][0]=0;
        for (int i=1; i<=n; i++)
            for (int k=1; k<=min(i, K); k++)
                for (int j=k; j<=i; j++)
                    dp[i][k]=min(dp[i][k], dp[j-1][k-1]+count(s, j, i));
                
        return dp[n][K];
    }
    int count(string &s, int a, int b)
    {
        int ret=0;
        while (a<b)
        {
            if (s[a]!=s[b]) ret+=1;
            a++, b--;
        }
        return ret;
    }
};
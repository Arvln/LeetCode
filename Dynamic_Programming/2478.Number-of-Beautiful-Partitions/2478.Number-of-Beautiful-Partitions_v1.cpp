class Solution {
public:
    int beautifulPartitions(string s, int K, int minLength) {
        int n=s.size();
        int M=1e9+7;
        s="#"+s;
        vector<vector<int>>dp(n+1, vector<int>(K+1, 0));
        dp[0][0]=1;

        for (int i=1; i<=n; i++)
            for (int k=1; k<=min(i, K); k++)
                if (isPrime(s[i])==false)
                    for (int j=k; j<=i-minLength+1; j++)
                        if (isPrime(s[j]))
                        {
                            dp[i][k]+=dp[j-1][k-1];
                            dp[i][k]%=M;
                        }
        return dp[n][K];
    }
    bool isPrime(char c)
    {
        return c=='2'||c=='3'||c=='5'||c=='7';
    }
};
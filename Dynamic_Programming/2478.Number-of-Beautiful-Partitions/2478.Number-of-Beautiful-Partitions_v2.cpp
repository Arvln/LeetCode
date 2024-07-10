class Solution {
public:
    int beautifulPartitions(string s, int K, int minLength) {
        int n=s.size();
        int M=1e9+7;
        s="#"+s;
        vector<vector<int>>dp(n+1, vector<int>(K+1, 0));
        dp[0][0]=1;

        for (int k=1; k<=K; k++)
        {
            int sum=0;
            for (int i=1; i<=n; i++)
            {
                if (i-minLength>=0&&isPrime(s[i-minLength+1]))
                {
                    sum+=dp[i-minLength][k-1];
                    sum%=M;
                }
                if (isPrime(s[i])==false) dp[i][k]=sum;
            }
        }
        return dp[n][K];
    }
    bool isPrime(char c)
    {
        return c=='2'||c=='3'||c=='5'||c=='7';
    }
};
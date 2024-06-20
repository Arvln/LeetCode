class Solution {
public:
    int integerBreak(int n) {
        if (n==2) return 1;
        else if (n==3) return 2;
        vector<int>dp(n+1);
        dp[2]=2;
        dp[3]=3;

        for (int i=4; i<=n; i++)
            for (int j=2; j<i; j++)
                dp[i]=max(dp[i], dp[j]*(i-j));
        return dp[n];
    }
};
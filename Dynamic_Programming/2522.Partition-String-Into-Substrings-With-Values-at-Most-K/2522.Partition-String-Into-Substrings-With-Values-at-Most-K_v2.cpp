class Solution {
public:
    int minimumPartition(string s, int k) {
        int n=s.size();
        int maxLen=to_string(k).size();
        s="#"+s;
        for (int i=1; i<=n; i++)
            if (s[i]-'0'>k) return -1;
        vector<int>dp(n+1, INT_MAX/2);
        dp[0]=0;

        for (int i=1; i<=n; i++)
            if (i-maxLen+1>=1&&stoi(s.substr(i-maxLen+1, maxLen))<=k) dp[i]=dp[i-maxLen]+1;
            else dp[i]=dp[max(0, i-maxLen+1)]+1;
        return dp[n];
    }
};
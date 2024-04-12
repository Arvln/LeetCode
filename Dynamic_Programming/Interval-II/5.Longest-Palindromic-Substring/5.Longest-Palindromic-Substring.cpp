class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<bool>>dp(n, vector<bool>(n, false));
        string ret=string(1, s[0]);
        for (int i=0; i<n; i++) dp[i][i]=true;
        for (int i=0; i+1<n; i++)
            if (s[i]==s[i+1])
            {
                dp[i][i+1]=true;
                ret=s.substr(i, 2);
            }

        for (int len=3; len<=n; len++)
            for (int i=0, j=i+len-1; j<n; i++, j++)
            {
                if (s[i]==s[j]&&dp[i+1][j-1]==true)
                {
                    dp[i][j]=true;
                    if (j-i+1>ret.size()) ret=s.substr(i, j-i+1);
                }
            }
        return ret;
    }
};
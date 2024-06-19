class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>>dp(m+1, vector<int>(n+1, 0));

        for (int k=0; k<strs.size(); k++)
        {
            int zero=0, one=0;
            for (char c : strs[k])
                if (c=='0') zero++;
                else one++;
            
            auto pre_dp=dp;
            for (int i=zero; i<=m; i++)
                for (int j=one; j<=n; j++)
                    dp[i][j]=max(dp[i][j], pre_dp[i-zero][j-one]+1);
        }
        return dp[m][n];
    }
};
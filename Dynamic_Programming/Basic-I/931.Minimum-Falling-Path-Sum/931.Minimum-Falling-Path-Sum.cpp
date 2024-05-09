class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        vector<vector<int>>dp(m, vector<int>(n));
        
        for (int j=0; j<n; j++)
            dp[0][j]=matrix[0][j];

        for (int i=1; i<m; i++)
            for (int j=0; j<n; j++)
            {
                int ret=INT_MAX;
                if (j>0)
                    ret=min(ret, dp[i-1][j-1]);
                ret=min(ret, dp[i-1][j]);
                if (j+1<n)
                    ret=min(ret, dp[i-1][j+1]);
                ret+=matrix[i][j];
                dp[i][j]=ret;
            }
        
        int ret=INT_MAX;
        for (int j=0; j<n; j++)
            ret=min(ret, dp[m-1][j]);
        return ret;
    }
};
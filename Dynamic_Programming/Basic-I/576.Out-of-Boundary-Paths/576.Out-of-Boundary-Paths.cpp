class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<int>>dp(m, vector<int>(n, 0));
        auto temp=dp;
        int M=1e9+7;

        for (int k=1; k<=maxMove; k++)
        {
            temp=dp;
            for (int i=0; i<m; i++)
                for (int j=0; j<n; j++)
                {
                    long ret=0;
                    ret+=i-1>=0?temp[i-1][j]:1;
                    ret+=j-1>=0?temp[i][j-1]:1;
                    ret+=i+1<m?temp[i+1][j]:1;
                    ret+=j+1<n?temp[i][j+1]:1;
                    dp[i][j]=ret%M;
                }
        }
        return dp[startRow][startColumn];
    }
};
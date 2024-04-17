class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m=mat.size(), n=mat[0].size();
        vector<vector<int>>pre(m+1, vector<int>(n+1, 0));
        for (int i=1; i<=m; i++)
            for (int j=1; j<=n; j++)
                pre[i][j]=pre[i-1][j]+pre[i][j-1]+mat[i-1][j-1]-pre[i-1][j-1];
        
        vector<vector<int>>ret(m, vector<int>(n));
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                int row1=max(0, i-k), row2=min(m-1, i+k)+1;
                int col1=max(0, j-k), col2=min(n-1, j+k)+1;
                ret[i][j]=pre[row2][col2]-pre[row1][col2]-pre[row2][col1]+pre[row1][col1];
            }
        return ret;
    }
};
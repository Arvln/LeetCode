class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        vector<vector<int>>ret(n, vector<int>(m));
        for (int i=0; i<max(m, n); i++)
            for (int j=0; j<=i; j++)
            {
                if (i<n&&j<m) ret[i][j]=matrix[j][i];
                if (j<n&&i<m) ret[j][i]=matrix[i][j];
            }
        return ret;
    }
};
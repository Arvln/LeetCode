class Solution {
    int dirs[4][2]{{0,1},{1,0},{0,-1},{-1,0}};
    vector<int>ret;
    vector<vector<int>>visited;
    int m, n;
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        m=matrix.size(), n=matrix[0].size();
        visited=vector<vector<int>>(m, vector<int>(n, 0));
        int i=0, j=0;
        ret.push_back(matrix[i][j]);
        visited[i][j]=1;
        while (ret.size()<m*n)
            for (int k=0; k<4; k++)
                moveNext(matrix, i, j, k);
        return ret;
    }
    void moveNext(vector<vector<int>> &matrix, int &i, int &j, int k)
    {
        int x=dirs[k][0], y=dirs[k][1];
        while (i+x>=0&&j+y>=0&&i+x<m&&j+y<n&&visited[i+x][j+y]==0)
        {
            i+=x;
            j+=y;
            ret.push_back(matrix[i][j]);
            visited[i][j]=1;
        }
    }
};
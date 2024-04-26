class Solution {
    int dirs[4][2]{{0,1},{1,0},{0,-1},{-1,0}};
    int n, count;
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ret(n, vector<int>(n, 0));
        this->n=n;
        int i=0, j=0;
        ret[i][j]=1;
        count=1;
        while (count<n*n)
            for (int k=0; k<4; k++)
                moveNext(ret, i, j, k);
        return ret;
    }
    void moveNext(vector<vector<int>> &grid, int &i, int &j, int k)
    {
        int x=dirs[k][0], y=dirs[k][1];
        while (i+x>=0&&j+y>=0&&i+x<n&&j+y<n&&grid[i+x][j+y]==0)
        {
            i+=x;
            j+=y;
            count++;
            grid[i][j]=count;
        }
    }
};
class Solution {
    vector<vector<int>>dirs{{1,0}, {0,1}, {-1,0}, {0,-1}};
public:
    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size();
        vector<vector<int>> Grid(3*n, vector<int>(3*n, 0));
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
            {
                if (grid[i][j]=='/')
                {
                    Grid[i*3][j*3+2]=1;
                    Grid[i*3+1][j*3+1]=1;
                    Grid[i*3+2][j*3+0]=1;
                }
                else if (grid[i][j]=='\\')
                {
                    Grid[i*3][j*3]=1;
                    Grid[i*3+1][j*3+1]=1;
                    Grid[i*3+2][j*3+2]=1;
                }
            }

        int ret=0;
        for (int i=0; i<3*n; i++)
            for (int j=0; j<3*n; j++)
            {
                if (Grid[i][j]!=0) continue;
                ret+=1;
                dfs(Grid, i, j);
            }
        return ret;
    }
    void dfs(vector<vector<int>>& Grid, int i, int j)
    {
        int n=Grid.size();
        if (i<0||j<0||i>=n||j>=n) return;
        if (Grid[i][j]!=0) return;

        Grid[i][j]=2;
        for (vector<int> dir : dirs)
            dfs(Grid, i+dir[0], j+dir[1]);
    }
};
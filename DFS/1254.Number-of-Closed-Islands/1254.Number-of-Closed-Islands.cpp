class Solution {
    int dirs[4][2]{{1,0},{0,1},{-1,0},{0,-1}};
    int m, n;
public:
    int closedIsland(vector<vector<int>>& grid) {
        m=grid.size(), n=grid[0].size();
        for (int i=0; i<m; i++)
        {
            if (grid[i][0]==0) dfs(grid, i, 0);
            if (grid[i][n-1]==0) dfs(grid, i, n-1);
        }
        for (int j=0; j<n; j++)
        {
            if (grid[0][j]==0) dfs(grid, 0, j);
            if (grid[m-1][j]==0) dfs(grid, m-1, j);
        }

        int ret=0;
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                if (grid[i][j]==0)
                {
                    ret++;
                    dfs(grid, i, j);
                }
        return ret;
    }
    void dfs(vector<vector<int>> &grid, int i, int j)
    {
        if (i<0||j<0||i>=m||j>=n) return;
        else if (grid[i][j]==1) return;
        grid[i][j]=1;

        for (auto dir : dirs)
            dfs(grid, i+dir[0], j+dir[1]);
    }
};
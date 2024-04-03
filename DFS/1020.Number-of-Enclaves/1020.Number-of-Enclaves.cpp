class Solution {
    int dirs[4][2]{{1,0},{0,1},{-1,0},{0,-1}};
    int m, n;
public:
    int numEnclaves(vector<vector<int>>& grid) {
        m=grid.size(), n=grid[0].size();

        for (int i=0; i<m; i++)
        {
            dfs(i, 0, grid);
            dfs(i, n-1, grid);
        }
        for (int j=0; j<n; j++)
        {
            dfs(0, j, grid);
            dfs(m-1, j, grid);
        }
        int ret=0;
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                if (grid[i][j]==1)
                    ret++;
        return ret;
    }
    void dfs(int i, int j, vector<vector<int>>&grid)
    {
        if (i<0||j<0||i>=m||j>=n) return;
        if (grid[i][j]!=1) return;

        grid[i][j]=2;
        for (auto dir : dirs)
            dfs(i+dir[0], j+dir[1], grid);
    }
};
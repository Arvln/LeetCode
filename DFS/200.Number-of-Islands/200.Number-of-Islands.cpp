class Solution {
    int dirs[4][2]{{1,0},{0,1},{-1,0},{0,-1}};
    int m, n;
public:
    int numIslands(vector<vector<char>>& grid) {
        m=grid.size(), n=grid[0].size();
        int ret=0;
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                if (grid[i][j]=='1')
                {
                    ret++;
                    dfs(grid, i, j);
                }
        return ret;
    }
    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        if (i<0||j<0||i>=m||j>=n) return;
        else if (grid[i][j]!='1') return;
        grid[i][j]='2';

        for (auto dir : dirs)
            dfs(grid, i+dir[0], j+dir[1]);
    }
};
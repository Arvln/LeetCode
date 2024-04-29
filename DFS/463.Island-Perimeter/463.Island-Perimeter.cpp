class Solution {
    int dirs[4][2]{{1,0},{0,1},{-1,0},{0,-1}};
    int m, n;
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        m=grid.size(), n=grid[0].size();
        int ret;
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                if (grid[i][j]==1) ret=dfs(grid, i, j);
        return ret;
    }
    int dfs(vector<vector<int>> &grid, int i, int j)
    {
        if (i<0||j<0||i>=m||j>=n) return 1;
        else if (grid[i][j]==0) return 1;
        else if (grid[i][j]!=1) return 0;

        grid[i][j]=2;
        int count=0;
        for (auto dir : dirs)
            count+=dfs(grid, i+dir[0], j+dir[1]);
        return count;
    }
};
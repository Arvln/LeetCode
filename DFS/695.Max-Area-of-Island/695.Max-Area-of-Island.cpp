class Solution {
    int dirs[4][2]{{1,0},{0,1},{-1,0},{0,-1}};
    int m, n;
    vector<vector<int>>visited;
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m=grid.size(), n=grid[0].size();
        visited=vector<vector<int>>(m, vector<int>(n, 0));
        int ret=0;
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                if (grid[i][j]==1&&visited[i][j]==0)
                    ret=max(ret, dfs(grid, i, j));
        return ret;
    }
    int dfs(vector<vector<int>> &grid, int i, int j)
    {
        if (i<0||j<0||i>=m||j>=n) return 0;
        else if (grid[i][j]==0) return 0;
        else if (visited[i][j]==1) return 0;

        visited[i][j]=1;
        int ret=1;
        for (auto dir : dirs)
            ret+=dfs(grid, i+dir[0], j+dir[1]);
        return ret;
    }
};
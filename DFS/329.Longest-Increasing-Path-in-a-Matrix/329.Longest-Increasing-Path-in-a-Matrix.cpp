class Solution {
    int dirs[4][2]{{1,0},{0,1},{-1,0},{0,-1}};
    int m, n;
    vector<vector<int>>visited;
    int memo[205][205];
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m=matrix.size(), n=matrix[0].size();
        visited=vector<vector<int>>(m, vector<int>(n, 0));
        int ret=0;
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                visited[i][j]=1;
                ret=max(ret, dfs(matrix, i, j));
                visited[i][j]=0;
            }
        return ret;
    }
    int dfs(vector<vector<int>> &grid, int i, int j)
    {
        if (memo[i][j]!=0) return memo[i][j];
        int ret=0;
        for (auto dir : dirs)
        {
            int x=i+dir[0], y=j+dir[1];
            if (x<0||y<0||x>=m||y>=n) continue;
            else if (visited[x][y]==1) continue;
            else if (grid[x][y]<=grid[i][j]) continue;

            visited[x][y]=1;
            ret=max(ret, dfs(grid, x, y));
            visited[x][y]=0;
        }
        memo[i][j]=1+ret;
        return 1+ret;
    }
};
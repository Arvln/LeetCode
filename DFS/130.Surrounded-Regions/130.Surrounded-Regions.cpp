class Solution {
    int dirs[4][2]{{1,0},{0,1},{-1,0},{0,-1}};
    int m, n;
public:
    void solve(vector<vector<char>>& board) {
        m=board.size(), n=board[0].size();
        vector<vector<int>>visited(m, vector<int>(n, 0));
        for (int i=0; i<m; i++)
        {
            if (board[i][0]=='O') dfs(board, i, 0, visited);
            if (board[i][n-1]=='O') dfs(board, i, n-1, visited);
        }
        for (int j=0; j<n; j++)
        {
            if (board[0][j]=='O') dfs(board, 0, j, visited);
            if (board[m-1][j]=='O') dfs(board, m-1, j, visited);
        }

        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                if (board[i][j]=='O'&&visited[i][j]==0)
                    board[i][j]='X';
    }
    void dfs(vector<vector<char>> &grid, int i, int j, vector<vector<int>> &visited)
    {
        if (i<0||j<0||i>=m||j>=n) return;
        else if (grid[i][j]=='X') return;
        else if (visited[i][j]==1) return;

        visited[i][j]=1;
        for (auto dir : dirs)
            dfs(grid, i+dir[0], j+dir[1], visited);
    }
};
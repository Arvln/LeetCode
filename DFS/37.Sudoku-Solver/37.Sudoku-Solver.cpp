class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board, 0, 0);
    }
    bool dfs(vector<vector<char>>& board, int i, int j)
    {
        if (i==9) return true;
        if (j==9) return dfs(board, i+1, 0);
        if (board[i][j]!='.') return dfs(board, i, j+1);

        for (char k='1'; k<='9'; k++)
        {
            if (!isValid(board, i, j, k)) continue;

            board[i][j]=k;
            if (dfs(board, i, j))
                return true;
            board[i][j]='.';
        }
        return false;
    }
    bool isValid(vector<vector<char>>& board, int i, int j, char k)
    {
        for (int row=0; row<9; row++)
            if (board[row][j]==k)
                return false;
        for (int col=0; col<9; col++)
            if (board[i][col]==k)
                return false;
        int m=i/3*3, n=j/3*3;
        for (int p=0; p<3; p++)
            for (int q=0; q<3; q++)
                if (board[m+p][n+q]==k)
                    return false;
        return true;
    }
};
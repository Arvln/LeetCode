class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i=0; i<9; i++)
            for (int j=0; j<9; j++)
                if (board[i][j]!='.'&&!isValid(board, i, j)) return false;
        return true;
    }
    bool isValid(vector<vector<char>> &board, int i, int j)
    {
        for (int x=0; x<9; x++)
            if (x!=i&&board[x][j]==board[i][j]) return false;
        for (int y=0; y<9; y++)
            if (y!=j&&board[i][y]==board[i][j]) return false;
        
        int m=i/3*3, n=j/3*3;
        for (int x=m; x<m+3; x++)
            for (int y=n; y<n+3; y++)
                if (x!=i&&y!=j&&board[x][y]==board[i][j]) return false;
        return true;
    }
};
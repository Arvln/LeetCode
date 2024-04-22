class Solution {
    vector<string>board;
    int ret=0;
public:
    int totalNQueens(int n) {
        board=vector<string>(n, string(n, '.'));
        dfs(n, 0);
        return ret;
    }
    void dfs(int n, int i)
    {
        if (i==n)
        {
            ret++;
            return;
        }

        for (int k=0; k<n; k++)
        {
            if (!isValid(i, k, n)) continue;

            board[i][k]='Q';
            dfs(n, i+1);
            board[i][k]='.';
        }
    }
    bool isValid(int i, int j, int n)
    {
        for (int p=i-1; p>=0; p--)
            if (board[p][j]=='Q') return false;
        for (int p=i-1, q=j-1; p>=0&&q>=0; p--, q--)
            if (board[p][q]=='Q') return false;
        for (int p=i-1, q=j+1; p>=0&&q<n; p--, q++)
            if (board[p][q]=='Q') return false;
        return true;
    }
};
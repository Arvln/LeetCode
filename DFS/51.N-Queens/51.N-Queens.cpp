class Solution {
    vector<vector<string>>ret;
    vector<string>path;
    int n;
public:
    vector<vector<string>> solveNQueens(int n) {
        path=vector<string>(n, string(n, '.'));
        this->n=n;
        dfs(0);
        return ret;
    }
    void dfs(int i)
    {
        if (i==n)
        {
            ret.push_back(path);
            return;
        }

        for (int j=0; j<n; j++)
        {
            if (!isValid(i, j)) continue;

            path[i][j]='Q';
            dfs(i+1);
            path[i][j]='.';
        }
    }
    bool isValid(int i, int j)
    {
        for (int x=i-1; x>=0; x--)
            if (path[x][j]=='Q') return false;

        for (int x=i-1, y=j-1; x>=0&&y>=0; x--, y--)
            if (path[x][y]=='Q') return false;

        for (int x=i-1, y=j+1; x>=0&&y<n; x--, y++)
            if (path[x][y]=='Q') return false;

        return true;
    }
};
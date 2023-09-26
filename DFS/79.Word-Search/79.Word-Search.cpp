class Solution {
    int m, n;
    vector<pair<int, int>>dirs{{1,0}, {0,1}, {-1,0}, {0,-1}};
public:
    bool exist(vector<vector<char>>& board, string word) {
        m=board.size(), n=board[0].size();
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                if (board[i][j]!=word[0]) continue;
                vector<vector<int>>visited(m, vector<int>(n, 0));
                if(dfs(board, word, i, j, 0, visited))
                    return true;
            }
        return false;
    }
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int k, vector<vector<int>>& visited)
    {
        if (k==word.size()) return true;
        if (i<0||j<0||i>=m||j>=n) return false;
        if (visited[i][j]) return false;
        if (board[i][j]!=word[k]) return false;

        visited[i][j]=1;
        for (auto [x, y] : dirs)
            if (dfs(board, word, i+x, j+y, k+1, visited))
                return true;
        visited[i][j]=0;
        return false;
    }
};
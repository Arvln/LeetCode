class Solution {
    int dirs[4][2]{{1,0},{0,1},{-1,0},{0,-1}};
    int m, n;
    vector<vector<int>>visited;
    string word;
public:
    bool exist(vector<vector<char>>& board, string word) {
        m=board.size(), n=board[0].size();
        visited=vector<vector<int>>(m, vector<int>(n, 0));
        this->word=word;
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                if (dfs(board, i, j, 0)) return true;
        return false;
    }
    bool dfs(vector<vector<char>> &board, int i, int j, int cur)
    {
        if (cur==word.size()) return true;
        else if (i<0||j<0||i>=m||j>=n) return false;
        else if (board[i][j]!=word[cur]) return false;
        else if (visited[i][j]==1) return false;
        
        visited[i][j]=1;
        for (auto dir : dirs)
            if (dfs(board, i+dir[0], j+dir[1], cur+1)) return true;
        visited[i][j]=0;
        return false;
    }
};
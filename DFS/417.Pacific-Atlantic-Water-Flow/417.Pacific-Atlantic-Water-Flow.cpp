class Solution {
    int dirs[4][2]{{1,0},{0,1},{-1,0},{0,-1}};
    int m, n;
    vector<vector<int>>heights;
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m=heights.size(), n=heights[0].size();
        this->heights=heights;
        vector<vector<int>>pac(m, vector<int>(n, 0));
        vector<vector<int>>atl(m, vector<int>(n ,0));
        for (int i=0; i<m; i++)
        {
            dfs(pac, i, 0, INT_MIN);
            dfs(atl, i, n-1, INT_MIN);
        }
        for (int j=0; j<n; j++)
        {
            dfs(pac, 0, j, INT_MIN);
            dfs(atl, m-1, j, INT_MIN);
        }
        vector<vector<int>>rets;
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                if (pac[i][j]==1&&atl[i][j]==1) rets.push_back({i, j});
        return rets;
    }
    void dfs(vector<vector<int>> &visited, int i, int j, int preHeight)
    {
        if (i<0||j<0||i>=m||j>=n) return;
        else if (visited[i][j]==1) return;
        else if (preHeight>heights[i][j]) return;
        visited[i][j]=1;

        for (auto dir : dirs)
            dfs(visited, i+dir[0], j+dir[1], heights[i][j]);
    }
};
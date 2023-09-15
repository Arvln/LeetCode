class Solution {
    int m, n;
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m=heights.size(), n=heights[0].size();
        vector<vector<int>>pac(m, vector<int>(n, 0));
        vector<vector<int>>alt(m, vector<int>(n, 0));

        for (int i=0; i<m; i++)
        {
            dfs(i, 0, INT_MIN, heights, pac);
            dfs(i, n-1, INT_MIN, heights, alt);
        }
        for (int j=0; j<n; j++)
        {
            dfs(0, j, INT_MIN, heights, pac);
            dfs(m-1, j, INT_MIN, heights, alt);
        }

        vector<vector<int>>ret;
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                if (pac[i][j]&&alt[i][j])
                    ret.push_back({i, j});

        return ret;
    }
    void dfs(int i, int j, int height, vector<vector<int>>& heights, vector<vector<int>>& sea)
    {
        if (i<0||j<0||i>=m||j>=n) return;
        if (sea[i][j]||height>heights[i][j]) return;

        sea[i][j]=1;
        dfs(i-1, j, heights[i][j], heights, sea);
        dfs(i+1, j, heights[i][j], heights, sea);
        dfs(i, j-1, heights[i][j], heights, sea);
        dfs(i, j+1, heights[i][j], heights, sea);
    }
};
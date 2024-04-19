class Solution {
    int dirs[4][2]{{1,0},{0,1},{-1,0},{0,-1}};
    int m, n;
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        m=grid.size(), n=grid[0].size();
        int ret=0;
        unordered_set<string>Set;
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                if (grid[i][j]==1)
                {
                    string id=dfs(grid, i, j, -1);

                    if (Set.find(id)==Set.end())
                    {
                        ret++;
                        Set.insert(id);
                    }
                }
        return ret;
    }
    string dfs(vector<vector<int>> &grid, int i, int j, int dir)
    {
        if (i<0||j<0||i>=m||j>=n) return "#";
        if (grid[i][j]==0) return "#";

        grid[i][j]=0;
        string ret=to_string(dir);
        for (int k=0; k<4; k++)
            ret+=","+dfs(grid, i+dirs[k][0], j+dirs[k][1], k);
        return ret;
    }
};
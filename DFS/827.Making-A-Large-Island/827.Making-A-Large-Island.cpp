class Solution {
    int dirs[4][2]{{1,0},{0,1},{-1,0},{0,-1}};
    int n;
public:
    int largestIsland(vector<vector<int>>& grid) {
        n=grid.size();
        unordered_map<int, int>area;
        int mark=2;
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                if (grid[i][j]==1)
                {
                    area[mark]=dfs(grid, i, j, mark);
                    mark++;
                }
        
        int ret=0;
        unordered_set<int>used;
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                if (grid[i][j]==0)
                {
                    int sum=1;
                    for (auto dir : dirs)
                    {
                        int x=i+dir[0], y=j+dir[1];
                        if (x<0||y<0||x>=n||y>=n) continue;
                        int mark=grid[x][y];
                        if (used.find(mark)!=used.end()) continue;
                        
                        sum+=area[mark];
                        used.insert(mark);
                    }
                    ret=max(ret, sum);
                    used.clear();
                }
        if (ret==0) return n*n;
        else return ret;
    }
    int dfs(vector<vector<int>> &grid, int i, int j, int mark)
    {
        if (i<0||j<0||i>=n||j>=n) return 0;
        else if (grid[i][j]!=1) return 0;

        grid[i][j]=mark;
        int ret=1;
        for (auto dir : dirs)
            ret+=dfs(grid, i+dir[0], j+dir[1], mark);
        return ret;
    }
};
class Solution {
    int dirs[4][2]{{1,0},{0,1},{-1,0},{0,-1}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        queue<pair<int, int>>q;
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                if (grid[i][j]==2) q.push({i, j});
        
        int ret=-1;
        while (!q.empty())
        {
            for (int size=q.size(); size>0; size--)
            {
                auto [i, j]=q.front();
                q.pop();

                for (auto dir : dirs)
                {
                    int x=i+dir[0], y=j+dir[1];
                    if (x<0||y<0||x>=m||y>=n) continue;
                    else if (grid[x][y]!=1) continue;

                    q.push({x, y});
                    grid[x][y]=2;
                }
            }
            ret++;
        }

        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                if (grid[i][j]==1) return -1;
        return max(0, ret);
    }
};
class Solution {
    int dirs[8][2]{{1,0},{0,1},{-1,0},{0,-1},{1,-1},{-1,1},{1,1},{-1,-1}};
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        queue<pair<int, int>>q;
        vector<vector<int>>visited(m, vector<int>(n, 0));
        if (grid[0][0]==0)
        {
            q.push({0, 0});
            visited[0][0]=1;
        }
        
        int ret=1;
        while (!q.empty())
        {
            for (int size=q.size(); size>0; size--)
            {
                auto [i, j]=q.front();
                q.pop();

                if (i==m-1&&j==n-1) return ret;

                for (auto dir : dirs)
                {
                    int x=i+dir[0], y=j+dir[1];
                    if (x<0||y<0||x>=m||y>=n) continue;
                    else if (grid[x][y]==1) continue;
                    else if (visited[x][y]==1) continue;

                    q.push({x, y});
                    visited[x][y]=1;
                }
            }
            ret++;
        }
        return -1;
    }
};
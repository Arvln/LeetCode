class Solution {
    int dirs[4][2]{{1,0},{0,1},{-1,0},{0,-1}};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        queue<pair<int, int>>q;
        vector<vector<int>>visited(m, vector<int>(n, 0));
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                if (mat[i][j]==0)
                {
                    q.push({i, j});
                    visited[i][j]=1;
                }
        int dis=0;
        while (!q.empty())
        {
            for (int size=q.size(); size>0; size--)
            {
                auto [i, j]=q.front();
                q.pop();
                mat[i][j]=dis;

                for (auto dir : dirs)
                {
                    int x=i+dir[0], y=j+dir[1];
                    if (x<0||y<0||x>=m||y>=n) continue;
                    if (visited[x][y]==1) continue;

                    q.push({x, y});
                    visited[x][y]=1;
                }
            }
            dis++;
        }
        return mat;
    }
};
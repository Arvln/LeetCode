class Solution {
    int dirs[4][2]{{1,0},{0,1},{-1,0},{0,-1}};
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m=maze.size(), n=maze[0].size();
        queue<pair<int, int>>q;
        vector<vector<int>>visited(m, vector<int>(n, 0));
        q.push({entrance[0], entrance[1]});
        visited[entrance[0]][entrance[1]]=1;
        int dis=0;
        while (!q.empty())
        {
            for (int size=q.size(); size>0; size--)
            {
                auto [i, j]=q.front();
                q.pop();
                
                for (auto dir : dirs)
                {
                    int x=i+dir[0], y=j+dir[1];
                    if (x<0||y<0||x>=m||y>=n)
                    {
                        if (i==entrance[0]&&j==entrance[1]) continue;
                        return dis;
                    }
                    else if (maze[x][y]=='+') continue;
                    else if (visited[x][y]==1) continue;

                    q.push({x, y});
                    visited[x][y]=1;
                }
            }
            dis++;
        }
        return -1;
    }
};
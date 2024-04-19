class Solution {
    int dirs[4][2]{{1,0},{0,1},{-1,0},{0,-1}};
    int m, n;
public:
    bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        m=maze.size(), n=maze[0].size();
        queue<pair<int, int>>q;
        vector<vector<int>>visited(m, vector<int>(n, 0));
        q.push({start[0], start[1]});
        visited[start[0]][start[1]]=1;
        while (!q.empty())
        {
            auto [i, j]=q.front();
            q.pop();

            for (int k=0; k<4; k++)
            {
                auto [x, y]=moveNext(maze, i, j, k);
                if (x==destination[0]&&y==destination[1]) return true;
                if (visited[x][y]==1) continue;
                q.push({x, y});
                visited[x][y]=1;
            }
        }
        return false;
    }
    pair<int, int> moveNext(vector<vector<int>> &maze, int i, int j, int k)
    {
        int x=dirs[k][0], y=dirs[k][1];
        while (i+x>=0&&j+y>=0&&i+x<m&&j+y<n&&maze[i+x][j+y]!=1)
        {
            i+=x;
            j+=y;
        }
        return {i, j};
    }
};
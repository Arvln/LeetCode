using AI3=array<int, 3>;
class Solution {
    int dirs[4][2]{{1,0},{0,1},{-1,0},{0,-1}};
    int m, n;
public:
    int shortestDistance(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        m=maze.size(), n=maze[0].size();
        priority_queue<AI3, vector<AI3>, greater<>>pq; // {step, i, j}
        vector<vector<int>>visited(m, vector<int>(n, 0));
        pq.push({0, start[0], start[1]});

        while (!pq.empty())
        {
            auto cur=pq.top();
            pq.pop();
            int step=cur[0], i=cur[1], j=cur[2];

            if (i==destination[0]&&j==destination[1]) return step;
            else if (visited[i][j]==1) continue;
            visited[i][j]=1;

            for (int k=0; k<4; k++)
            {
                AI3 next=Next(maze, i, j, k);
                int shift=next[0], x=next[1], y=next[2];
                if (visited[x][y]==1) continue;

                pq.push({step+shift, x, y});
            }
        }
        return -1;
    }
    AI3 Next(vector<vector<int>> &maze, int i, int j, int k)
    {
        int x=dirs[k][0], y=dirs[k][1];
        int count=0;
        while (i+x>=0&&j+y>=0&&i+x<m&&j+y<n&&maze[i+x][j+y]==0)
        {
            i+=x;
            j+=y;
            count++;
        }
        return {count, i, j};
    }
};
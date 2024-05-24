using AI3=array<int, 3>;
class Solution {
    int dirs[4][2]{{1,0},{0,1},{-1,0},{0,-1}};
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size(), n=heights[0].size();
        priority_queue<AI3, vector<AI3>, greater<>>pq; // {effort, i, j}
        vector<vector<int>>visited(m, vector<int>(n, 0));
        pq.push({0, 0, 0});
        while (!pq.empty())
        {
            auto cur=pq.top();
            int effort=cur[0], i=cur[1], j=cur[2];
            pq.pop();

            if (i==m-1&&j==n-1) return effort;
            else if (visited[i][j]==1) continue;
            visited[i][j]=1;

            for (auto dir : dirs)
            {
                int x=i+dir[0], y=j+dir[1];
                if (x<0||y<0||x>=m||y>=n) continue;
                else if (visited[x][y]==1) continue;

                int diff=abs(heights[i][j]-heights[x][y]);
                pq.push({max(effort, diff), x, y});
            }
        }
        return 0;
    }
};
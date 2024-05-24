class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int l=0, r=1e6;
        while (l<=r)
        {
            int mid=l+(r-l)/2;

            if (canReach(heights, mid)) r=mid-1;
            else l=mid+1;
        }
        return l;
    }
    bool canReach(vector<vector<int>> &heights, int diff)
    {
        int m=heights.size(), n=heights[0].size();
        int dirs[4][2]{{1,0},{0,1},{-1,0},{0,-1}};
        queue<pair<int, int>>q;
        vector<vector<bool>>visited(m, vector<bool>(n, false));
        q.push({0, 0});
        visited[0][0]=true;
        while (!q.empty())
        {
            auto [i, j]=q.front();
            q.pop();

            for (auto dir : dirs)
            {
                int x=i+dir[0], y=j+dir[1];
                if (x<0||y<0||x>=m||y>=n) continue;
                else if (visited[x][y]) continue;
                else if (abs(heights[i][j]-heights[x][y])>diff) continue;

                q.push({x, y});
                visited[x][y]=true;
            }
        }
        return visited[m-1][n-1];
    }
};
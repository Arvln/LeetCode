class Solution {
    int dirs[8][2]{{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
public:
    int minKnightMoves(int x, int y) {
        int m=800, n=800;
        int src=400*n+400, dst=(x+400)*n+(y+400);
        queue<int>q;
        unordered_set<int>visited;
        q.push(src);
        visited.insert(src);
        int ret=0;
        while (!q.empty())
        {
            for (int size=q.size(); size>0; size--)
            {
                int cur=q.front();
                int i=cur/n, j=cur%n;
                q.pop();

                if (cur==dst) return ret;

                for (auto dir : dirs)
                {
                    int x=i+dir[0], y=j+dir[1];

                    if (x<0||y<0||x>=m||y>=n) continue;
                    else if (visited.find(x*n+y)!=visited.end()) continue;

                    q.push(x*n+y);
                    visited.insert(x*n+y);
                }
            }
            ret++;
        }
        return -1;
    }
};
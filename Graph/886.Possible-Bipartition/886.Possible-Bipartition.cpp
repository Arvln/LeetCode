class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>nexts(n+1);
        for (auto &dislike : dislikes)
        {
            int a=dislike[0], b=dislike[1];
            nexts[a].push_back(b);
            nexts[b].push_back(a);
        }
        vector<int>visited(n+1, 0);
        vector<int>color(n+1, 0);

        for (int i=1; i<=n; i++)
        {
            if (visited[i]==1) continue;

            queue<int>q;
            q.push(i);
            visited[i]=1;
            color[i]=1;
            while (!q.empty())
            {
                int cur=q.front();
                q.pop();

                for (int next : nexts[cur])
                {
                    if (visited[next]==0)
                    {
                        color[next]=1-color[cur];
                        q.push(next);
                        visited[next]=1;
                    }
                    else if (color[next]==color[cur]) return false;
                }
            }
        }
        return true;
    }
};
class Solution {
public:
    int treeDiameter(vector<vector<int>> &edges) {
        int n=edges.size();
        if (n==0) return 0;
        vector<vector<int>>nexts(n+1);
        for (auto edge : edges)
        {
            int a=edge[0], b=edge[1];
            nexts[a].push_back(b);
            nexts[b].push_back(a);
        }

        int farestNode;
        queue<int>q;
        vector<int>visited(n+1);
        q.push(0);
        visited[0]=1;
        while (!q.empty())
        {
            int cur=q.front();
            q.pop();
            farestNode=cur;

            for (int next : nexts[cur])
            {
                if (visited[next]==1) continue;
                q.push(next);
                visited[next]=1;
            }
        }
        for (int i=0; i<=n; i++)
            visited[i]=0;

        q.push(farestNode);
        visited[farestNode]=1;
        int maxDistance=0;
        while (!q.empty())
        {
            for (int size=q.size(); size>0; size--)
            {
                int cur=q.front();
                q.pop();

                for (int next : nexts[cur])
                {
                    if (visited[next]==1) continue;
                    q.push(next);
                    visited[next]=1;
                }
            }
            maxDistance++;
        }
        return maxDistance-1;
    }
};
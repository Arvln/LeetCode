class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>>nexts(n);
        vector<int>degree(n, 0);
        for (auto &edge : edges)
        {
            int a=edge[0], b=edge[1];
            nexts[a].push_back(b);
            nexts[b].push_back(a);
            degree[a]++;
            degree[b]++;
        }
        
        queue<int>q;
        vector<int>visited(n, 0);
        for (int i=0; i<n; i++)
            if (degree[i]==1) q.push(i);
        
        int count=n;
        while (!q.empty()&&count>2)
        {
            for (int size=q.size(); size>0; size--)
            {
                int cur=q.front();
                q.pop();
                count--;
                visited[cur]=1;

                for (int next : nexts[cur])
                {
                    if (visited[next]==1) continue;

                    degree[next]--;
                    if (degree[next]==1) q.push(next);
                }
            }
        }

        vector<int>ret;
        for (int i=0; i<n; i++)
            if (visited[i]==0) ret.push_back(i);
        return ret;
    }
};
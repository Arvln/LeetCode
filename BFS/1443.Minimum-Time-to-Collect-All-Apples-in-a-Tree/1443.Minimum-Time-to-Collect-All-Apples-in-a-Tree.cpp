class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>>nexts(n);
        vector<int>degree(n, 0);
        for (auto edge : edges)
        {
            int a=edge[0], b=edge[1];
            nexts[a].push_back(b);
            nexts[b].push_back(a);
            degree[a]++;
            degree[b]++;
        }
        int count=n;
        queue<int>q;
        hasApple[0]=true;
        for (int i=0; i<n; i++)
            if (degree[i]==1&&hasApple[i]==false)
            {
                q.push(i);
                count--;
            }
        while (!q.empty())
        {
            int cur=q.front();
            q.pop();

            for (int next : nexts[cur])
            {
                degree[next]--;
                if (degree[next]==1&&hasApple[next]==false)
                {
                    q.push(next);
                    count--;
                }
            }
        }
        return (count-1)*2;
    }
};
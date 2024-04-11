using PII=pair<int, int>;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>>nexts(n+1);
        for (auto &time : times)
        {
            int u=time[0], v=time[1], w=time[2];
            nexts[u].push_back({v, w});
        }
        priority_queue<PII, vector<PII>, greater<>>pq; // {cost, label}
        pq.push({0, k});
        vector<int>visited(n+1, 0);
        int ret=0;
        while (!pq.empty())
        {
            auto [cost, cur]=pq.top();
            pq.pop();

            if (visited[cur]==1) continue;
            visited[cur]=1;
            ret=max(ret, cost);

            for (auto &[next, time] : nexts[cur])
            {
                if (visited[next]==1) continue;

                pq.push({cost+time, next});
            }
        }
        for (int i=1; i<=n; i++)
            if (visited[i]==0) return -1;
        return ret;
    }
};
using PII=pair<int, int>; // {time, id}
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>>nexts(n);
        for (int i=0; i<n; i++)
            if (manager[i]!=-1) nexts[manager[i]].push_back(i);

        priority_queue<PII, vector<PII>, greater<>>pq;
        vector<int>visited(n, 0);
        pq.push({0, headID});
        int ret=0;
        while (!pq.empty())
        {
            auto [time, id]=pq.top();
            pq.pop();

            if (visited[id]==1) continue;
            visited[id]=1;
            ret=max(ret, time);

            for (int next : nexts[id])
            {
                if (visited[next]==1) continue;
                pq.push({time+informTime[id], next});
            }
        }
        return ret;
    }
};
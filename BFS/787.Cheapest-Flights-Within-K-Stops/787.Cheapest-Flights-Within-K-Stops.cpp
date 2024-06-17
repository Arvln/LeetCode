using AI3=array<int, 3>;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>>nexts(n);
        for (auto &flight : flights)
        {
            int from=flight[0], to=flight[1], price=flight[2];
            nexts[from].push_back({to, price});
        }

        priority_queue<AI3, vector<AI3>, greater<>>pq; // {cost, time, city}
        vector<vector<int>>visited(n, vector<int>(k+2, 0));
        pq.push({0, 0, src});
        while (!pq.empty())
        {
            AI3 cur=pq.top();
            pq.pop();

            int cost=cur[0], time=cur[1], city=cur[2];

            if (city==dst) return cost;
            else if (time==k+1) continue;
            else if (visited[city][time]==1) continue;
            visited[city][time]=1;

            for (auto &[next, price] : nexts[city])
            {
                if (visited[next][time+1]==1) continue;

                pq.push({cost+price, time+1, next});
            }
        }
        return -1;
    }
};
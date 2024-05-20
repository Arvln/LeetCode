class Solution {
    vector<vector<pair<int, double>>>nexts;
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        nexts.resize(n);
        for (int i=0; i<edges.size(); i++)
        {
            int a=edges[i][0], b=edges[i][1];
            double prob=succProb[i];
            nexts[a].push_back({b, prob});
            nexts[b].push_back({a, prob});
        }
        priority_queue<pair<double, int>>pq; // {prob, node}
        vector<int>visited(n, 0);
        pq.push({1.0, start_node});
        while (!pq.empty())
        {
            auto [prob, cur]=pq.top();
            pq.pop();

            if (cur==end_node) return prob;
            else if (visited[cur]==1) continue;
            visited[cur]=1;

            for (auto &[next, next_prob] : nexts[cur])
            {
                if (visited[next]==1) continue;

                pq.push({prob*next_prob, next});
            }
        }
        return 0;
    }
};
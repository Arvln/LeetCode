class Solution {
    vector<vector<int>>rets;
    vector<int>path{0};
    int n;
    vector<vector<int>>graph;
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        this->graph=graph;
        n=graph.size();
        dfs(0);
        return rets;
    }
    void dfs(int node)
    {
        if (node==n-1)
        {
            rets.push_back(path);
            return;
        }

        for (int next : graph[node])
        {
            path.push_back(next);
            dfs(next);
            path.pop_back();
        }
    }
};
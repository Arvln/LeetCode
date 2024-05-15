class Solution {
    unordered_map<string, queue<string>>nexts;
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(), tickets.end());
        for (auto &ticket : tickets)
            nexts[ticket[0]].push(ticket[1]);
        return dfs("JFK");
    }
    vector<string> dfs(string cur)
    {
        vector<vector<string>>paths;
        while (!nexts[cur].empty())
        {
            string next=nexts[cur].front();
            nexts[cur].pop();
            paths.push_back(dfs(next));
        }

        vector<string>ret{cur};
        for (int i=paths.size()-1; i>=0; i--)
            for (string &city : paths[i])
                ret.push_back(city);
        return ret;
    }
};
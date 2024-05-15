class Solution {
    unordered_map<string, queue<string>>nexts;
    vector<string>ret;
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(), tickets.end());
        for (auto &ticket : tickets)
            nexts[ticket[0]].push(ticket[1]);
        dfs("JFK");
        reverse(ret.begin(), ret.end());
        return ret;
    }
    void dfs(string cur)
    {
        while (!nexts[cur].empty())
        {
            string next=nexts[cur].front();
            nexts[cur].pop();
            dfs(next);
        }
        ret.push_back(cur);
    }
};
class Solution {
    unordered_map<int, vector<int>>nexts;
    vector<int>rets;
public:
    vector<int> killProcess(vector<int> &pid, vector<int> &ppid, int kill) {
        for (int i=0; i<pid.size(); i++)
            nexts[ppid[i]].push_back(pid[i]);
        dfs(kill);
        return rets;
    }
    void dfs(int node)
    {
        rets.push_back(node);
        for (int next : nexts[node])
            dfs(next);
    }
};
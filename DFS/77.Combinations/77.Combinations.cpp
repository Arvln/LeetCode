class Solution {
    vector<vector<int>>rets;
    vector<int>path;
public:
    vector<vector<int>> combine(int n, int k) {
        dfs(n, k, 1);
        return rets;
    }
    void dfs(int n, int size, int pos)
    {
        if (path.size()==size)
        {
            rets.push_back(path);
            return;
        }

        for (int i=pos; i<=n; i++)
        {
            path.push_back(i);
            dfs(n, size, i+1);
            path.pop_back();
        }
    }
};
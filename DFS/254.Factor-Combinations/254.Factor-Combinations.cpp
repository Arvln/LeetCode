class Solution {
    vector<vector<int>>rets;
    vector<int>path;
public:
    vector<vector<int>> getFactors(int n) {
        dfs(n, 2);
        return rets;
    }
    void dfs(int n, int start)
    {
        if (path.size()>1&&n==1) rets.push_back(path);

        for (int num=start; num<=n; num++)
        {
            if (n%num!=0) continue;

            path.push_back(num);
            dfs(n/num, num);
            path.pop_back();
        }
    }
};
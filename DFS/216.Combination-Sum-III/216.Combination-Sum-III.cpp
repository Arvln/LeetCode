class Solution {
    vector<vector<int>>rets;
    vector<int>path;
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(k, n, 1);
        return rets;
    }
    void dfs(int k, int n, int start)
    {
        if (path.size()==k&&n==0)
        {
            rets.push_back(path);
            return;
        }

        for (int num=start; num<10; num++)
        {
            if (n<num) continue;

            path.push_back(num);
            dfs(k, n-num, num+1);
            path.pop_back();
        }
    }
};
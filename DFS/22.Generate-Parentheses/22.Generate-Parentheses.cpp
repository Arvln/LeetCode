class Solution {
    vector<string>rets;
    string path="";
public:
    vector<string> generateParenthesis(int n) {
        dfs(n, n);
        return rets;
    }
    void dfs(int left, int right)
    {
        if (left<0||right<0||left>right) return;
        else if (left==0&&right==0) rets.push_back(path);
        else
        {
            path.push_back('(');
            dfs(left-1, right);
            path.pop_back();
            path.push_back(')');
            dfs(left, right-1);
            path.pop_back();
        }
    }
};
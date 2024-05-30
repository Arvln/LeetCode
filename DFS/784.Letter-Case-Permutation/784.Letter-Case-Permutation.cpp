class Solution {
    vector<string>rets;
    string path;
public:
    vector<string> letterCasePermutation(string s) {
        dfs(s, 0);
        return rets;
    }
    void dfs(string &s, int cur)
    {
        if (cur==s.size())
        {
            rets.push_back(path);
            return;
        }

        if (isdigit(s[cur]))
        {
            path.push_back(s[cur]);
            dfs(s, cur+1);
            path.pop_back();
        }
        else
        {
            path.push_back(toupper(s[cur]));
            dfs(s, cur+1);
            path.pop_back();
            path.push_back(tolower(s[cur]));
            dfs(s, cur+1);
            path.pop_back();
        }
    }
};
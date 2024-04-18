class Solution {
    vector<vector<string>>rets;
    vector<string>path;
public:
    vector<vector<string>> partition(string s) {
        dfs(s, 0);
        return rets;
    }
    void dfs(string &s, int i)
    {
        if (i==s.size())
        {
            rets.push_back(path);
            return;
        }

        for (int j=i; j<s.size(); j++)
        {
            if (!isValid(s, i, j)) continue;

            path.push_back(s.substr(i, j-i+1));
            dfs(s, j+1);
            path.pop_back();
        }
    }
    bool isValid(string &s, int i, int j)
    {
        while (i<j)
        {
            if (s[i]!=s[j]) return false;
            i++, j--;
        }
        return true;
    }
};
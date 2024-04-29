class Solution {
    unordered_map<char, string>Map{
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };
    vector<string>ret;
    string path;
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return ret;
        dfs(digits, 0);
        return ret;
    }
    void dfs(string &s, int i)
    {
        if (i==s.size())
        {
            ret.push_back(path);
            return;
        }

        for (char c : Map[s[i]])
        {
            path.push_back(c);
            dfs(s, i+1);
            path.pop_back();
        }
    }
};
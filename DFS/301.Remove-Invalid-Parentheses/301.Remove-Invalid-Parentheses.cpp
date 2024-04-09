class Solution {
    vector<string>ret;
    string path, s;
    int maxLen;
public:
    vector<string> removeInvalidParentheses(string s) {
        int left=0, removed=0;
        for (char c : s)
        {
            if (c=='(') left++;
            else if (c==')')
            {
                left--;
                if (left<0)
                {
                    left=0;
                    removed++;
                }
            }
        }
        removed+=left;
        maxLen=s.size()-removed;
        this->s=s;
        dfs(0, 0, 0);
        return ret;
    }
    void dfs(int i, int left, int right)
    {
        if (left<right) return;
        else if (i==s.size())
        {
            if (left==right&&path.size()==maxLen) ret.push_back(path);
            return;
        }

        if (s[i]=='('||s[i]==')')
        {
            path.push_back(s[i]);
            dfs(i+1, left+(s[i]=='('), right+(s[i]==')'));
            path.pop_back();

            if (path.empty()||path.back()!=s[i])
                dfs(i+1, left, right);
        }
        else
        {
            path.push_back(s[i]);
            dfs(i+1, left, right);
            path.pop_back();
        }
    }
};
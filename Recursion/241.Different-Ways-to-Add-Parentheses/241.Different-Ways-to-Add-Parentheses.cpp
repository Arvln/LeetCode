class Solution {
    vector<int>dp[21][21];
public:
    vector<int> diffWaysToCompute(string expression) {
        return dfs(expression, 0, expression.size()-1);
    }
    vector<int> dfs(string& s, int i, int j)
    {
        if (!dp[i][j].empty()) return dp[i][j];

        for (int k=i; k<j; k++)
        {
            char c=s[k];
            if (c=='+'||c=='-'||c=='*')
            {
                vector<int> left=dfs(s, i, k);
                vector<int> right=dfs(s, k+1, j);

                for (int x : left)
                    for (int y : right)
                    {
                        if (c=='+')
                            dp[i][j].push_back(x+y);
                        else if (c=='-')
                            dp[i][j].push_back(x-y);
                        else if (c=='*')
                            dp[i][j].push_back(x*y);
                    }
            }
        }

        if (dp[i][j].empty())
            dp[i][j].push_back(stoi(s.substr(i, j-i+1)));
        
        return dp[i][j];
    }
};
class Solution {
    unordered_set<int>dp[32][32];
public:
    int scoreOfStudents(string s, vector<int>& answers) {
        int n=s.size();
        int cor_ans=correct_answer(s);
        dfs(s, 0, n-1);

        int ret=0;
        for (int ans : answers)
        {
            if (ans==cor_ans)
                ret+=5;
            else if (dp[0][n-1].find(ans)!=dp[0][n-1].end())
                ret+=2;
        }
        return ret;
    }
    void dfs(string& s, int i, int j)
    {
        if (!dp[i][j].empty()) return;

        for (int k=i; k<j; k++)
        {
            char c=s[k];
            if (c=='+'||c=='*')
            {
                dfs(s, i, k);
                dfs(s, k+1, j);

                for (int x : dp[i][k])
                    for (int y : dp[k+1][j])
                    {
                        if (c=='+'&&x+y<=1000)
                            dp[i][j].insert(x+y);
                        else if (c=='*'&&x*y<=1000)
                            dp[i][j].insert(x*y);
                    }
            }
        }

        if (dp[i][j].empty())
            dp[i][j].insert(stoi(s.substr(i, j-i+1)));
    }
    int correct_answer(string s)
    {
        s.insert(s.begin(), '+');
        int n=s.size();
        vector<int>nums;
        for (int i=0; i<n; i++)
        {
            int j=i+1;
            while(j<n&&isdigit(s[j]))
                j++;
            
            if (s[i]=='+')
                nums.push_back(stoi(s.substr(i+1, j-i)));
            else if (s[i]=='*')
                nums.back()*=stoi(s.substr(i+1, j-i));
            i=j-1;
        }
        int ret=0;
        for (int num : nums)
            ret+=num;

        return ret;
    }
};
class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n=1<<req_skills.size();
        vector<int>dp(n, INT_MAX/2);
        vector<pair<int, int>>pre(n);
        dp[0]=0;

        for (int status=0; status<n; status++)
            for (int i=0; i<people.size(); i++)
            {
                int newStatus=next(status, people[i], req_skills);
                dp[newStatus]=min(dp[newStatus], dp[status]+1);

                if (dp[newStatus]==dp[status]+1) pre[newStatus]={status, i};
            }
        
        int status=n-1;
        vector<int>ret;
        while (status!=0)
        {
            ret.push_back(pre[status].second);
            status=pre[status].first;
        }
        return ret;
    }
    int next(int status, vector<string> &people, vector<string> &target)
    {
        for (string skill : people)
            for (int i=0; i<target.size(); i++)
                if (((status>>i)&1)==0&&target[i]==skill)
                {
                    status+=1<<i;
                    break;
                }
        return status;
    }
};
class Solution {
    int M=1e9+7;
public:
    int numberWays(vector<vector<int>>& hats) {
        int n=hats.size();
        unordered_map<int, vector<int>>hatToPeople;
        for (int i=0; i<n; i++)
            for (int hat : hats[i])
                hatToPeople[hat].push_back(i);
        
        int N=1<<n;
        vector<int>dp(N, 0);
        dp[0]=1;

        for (int hat=1; hat<=40; hat++)
        {
            auto pre_dp=dp;
            for (int state=0; state<N; state++)
            {
                for (int person : hatToPeople[hat])
                {
                    if ((state>>person)&1==1) continue;
                    int next=state|(1<<person);
                    dp[next]=(dp[next]+pre_dp[state])%M;
                }
            }
        }
        return dp[N-1];
    }
};
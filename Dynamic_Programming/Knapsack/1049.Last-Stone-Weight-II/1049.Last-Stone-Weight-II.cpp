class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        stones.insert(stones.begin(), 0);
        int offset=3000;
        vector<vector<bool>>dp(n+1, vector<bool>(2*offset+1, false));
        dp[0][0+offset]=true;

        for (int i=1; i<=n; i++)
            for (int sum=-offset; sum<=offset; sum++)
            {
                if (sum-stones[i]>=-offset&&dp[i-1][sum-stones[i]+offset]==true)
                    dp[i][sum+offset]=true;
                if (sum+stones[i]<=offset&&dp[i-1][sum+stones[i]+offset]==true)
                    dp[i][sum+offset]=true;
            }
        
        for (int sum=0; sum<=offset; sum++)
            if (dp[n][sum+offset]==true) return sum;
        return 0;
    }
};
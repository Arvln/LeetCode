class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1, INT_MAX/2);
        dp[0]=0;
        for (int coin : coins)
            for (int total=coin; total<=amount; total++)
                dp[total]=min(dp[total], dp[total-coin]+1);

        if (dp[amount]==INT_MAX/2) return -1;
        else return dp[amount];
    }
};
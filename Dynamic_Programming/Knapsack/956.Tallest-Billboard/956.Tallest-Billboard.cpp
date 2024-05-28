class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int offset=5000;
        vector<int>dp(2*offset+1, INT_MIN/2);
        auto pre_dp=dp;
        dp[0+offset]=0;

        for (int i=0; i<rods.size(); i++)
        {
            int l=rods[i];
            pre_dp=dp;

            for (int diff=-offset; diff<=offset; diff++)
            {
                if (diff+l<=offset)
                    dp[diff+l+offset]=max(dp[diff+l+offset], pre_dp[diff+offset]+l);
                if (diff-l>=-offset)
                    dp[diff-l+offset]=max(dp[diff-l+offset], pre_dp[diff+offset]);
            }
        }
        return dp[0+offset];
    }
};
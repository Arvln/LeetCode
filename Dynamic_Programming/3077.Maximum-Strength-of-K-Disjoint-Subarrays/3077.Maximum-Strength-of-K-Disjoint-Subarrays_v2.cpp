using LL=long long;
class Solution {
public:
    long long maximumStrength(vector<int>& nums, int K) {
        int n=nums.size();
        reverse(nums.begin(), nums.end());
        nums.insert(nums.begin(), 0);
        vector<vector<vector<LL>>>dp(n+1, vector<vector<LL>>(K+1, vector<LL>(2, LLONG_MIN/2)));
        for (int i=0; i<=n; i++)
            dp[i][0][0]=0;

        for (int i=1; i<=n; i++)
            for (int k=1; k<=min(i, K); k++)
            {
                LL strength=pow(-1, k+1)*nums[i]*k;
                dp[i][k][0]=max(dp[i-1][k][0], dp[i-1][k][1]);
                dp[i][k][1]=max(max(dp[i-1][k-1][0], dp[i-1][k-1][1]), dp[i-1][k][1])+strength;
            }
        return max(dp[n][K][0], dp[n][K][1]);
    }
};
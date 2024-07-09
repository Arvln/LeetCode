using LL=long long;
class Solution {
public:
    long long maximumStrength(vector<int>& nums, int K) {
        int n=nums.size();
        reverse(nums.begin(), nums.end());
        nums.insert(nums.begin(), 0);
        vector<vector<LL>>dp(n+1, vector<LL>(K+1, LLONG_MIN/2));
        for (int i=0; i<=n; i++)
            dp[i][0]=0;

        for (int i=1; i<=n; i++)
            for (int k=1; k<=min(i, K); k++)
            {
                LL sum=0;
                for (int j=i; j>=k; j--)
                {
                    sum+=nums[j];
                    LL strength=pow(-1, k+1)*sum*k;
                    dp[i][k]=max(dp[i][k], dp[j-1][k-1]+strength);
                }
            }
        
        LL ret=LLONG_MIN;
        for (int i=1; i<=n; i++)
            ret=max(ret, dp[i][K]);
        return ret;
    }
};
using LL=long long;
class Solution {
    LL dp[105][105][105];
public:
    int sumOfPower(vector<int>& nums, int k) {
        int n=nums.size();
        int M=1e9+7;
        nums.insert(nums.begin(), 0);

        dp[0][0][0]=1;        
        for (int i=1; i<=n; i++)
            for (int s=0; s<=k; s++)
                for (int l=0; l<=n; l++)
                {
                    dp[i][s][l]+=dp[i-1][s][l];
                    if (s>=nums[i]&&l>=1) dp[i][s][l]+=dp[i-1][s-nums[i]][l-1];
                    dp[i][s][l]%=M;
                }
        
        vector<LL>power(n);
        power[0]=1;
        for (int i=1; i<n; i++)
            power[i]=power[i-1]*2%M;
        LL ret=0;
        for (int l=1; l<=n; l++)
            ret=(ret+power[n-l]*dp[n][k][l]%M)%M;
        return ret;
    }
};
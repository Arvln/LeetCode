class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>>dp(n, vector<int>(k, 0));
        vector<int>last(k, -1);

        int ret=0;
        for (int i=0; i<n; i++)
        {
            for (int m=0; m<k; m++)
            {
                int mod=(m-nums[i]%k+k)%k;

                if (last[mod]!=-1)
                {
                    int j=last[mod];
                    dp[i][m]=dp[j][m]+1;
                }
                else
                {
                    dp[i][m]=1;
                }
                ret=max(ret, dp[i][m]);
            }
            last[nums[i]%k]=i;
        }
        return ret;
    }
};
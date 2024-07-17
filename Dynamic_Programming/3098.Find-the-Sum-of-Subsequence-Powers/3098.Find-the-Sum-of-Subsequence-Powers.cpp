using LL=long long;
class Solution {
    int n;
    LL M=1e9+7;
public:
    int sumOfPowers(vector<int>& nums, int k) {
        n=nums.size();
        sort(nums.begin(), nums.end());
        nums.insert(nums.begin(), 0);
        
        LL ret=0;
        for (int a=1; a<=n; a++)
            for (int b=a+1; b<=n; b++)
            {
                int d=nums[b]-nums[a];
                ret+=count(nums, a, b, d, k);
                ret%=M;
            }
        return ret;
    }
    LL count(vector<int> &nums, int a, int b, int d, int K)
    {
        vector<vector<LL>>dp1(n+1, vector<LL>(K+1));
        vector<vector<LL>>dp2(n+1, vector<LL>(K+1));

        for (int i=1; i<=n; i++)
        {
            dp1[i][1]=1;
            dp2[i][1]=1;
        }

        for (int i=1; i<=a; i++)
            for (int j=2; j<=K; j++)
                for (int k=1; k<i; k++)
                    if (nums[i]-nums[k]>d)
                    {
                        dp1[i][j]+=dp1[k][j-1];
                        dp1[i][j]%=M;
                    }
        
        for (int i=n-1; i>=b; i--)
            for (int j=2; j<=K; j++)
                for (int k=n; k>i; k--)
                    if (nums[k]-nums[i]>=d)
                    {
                        dp2[i][j]+=dp2[k][j-1];
                        dp2[i][j]%=M;
                    }
        
        LL ret=0;
        for (int l=1; l<K; l++)
        {
            ret+=dp1[a][l]*dp2[b][K-l]%M;
            ret%=M;
        }
        return ret*d%M;
    }
};
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n, 1);
        vector<int>prev(n, -1);

        sort(nums.begin(), nums.end());
        for (int i=0; i<n; i++)
            for (int j=0; j<i; j++)
                if (nums[i]%nums[j]==0)
                {
                    dp[i]=max(dp[i], dp[j]+1);
                    if (dp[i]==dp[j]+1) prev[i]=j;
                }

        int maxLen=0, pos;
        for (int i=0; i<n; i++)
            if (dp[i]>maxLen)
            {
                maxLen=dp[i];
                pos=i;
            }
        
        vector<int>ret;
        while (pos!=-1)
        {
            ret.push_back(nums[pos]);
            pos=prev[pos];
        }
        return ret;
    }
};
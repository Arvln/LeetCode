class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>dp(n);
        deque<int>dq;
        for (int i=0; i<n; i++)
        {
            while (!dq.empty()&&i-dq.front()>k)
                dq.pop_front();
            
            dp[i]=nums[i];
            if (!dq.empty()) dp[i]=max(dp[i], dp[dq.front()]+nums[i]);

            while (!dq.empty()&&dp[dq.back()]<=dp[i])
                dq.pop_back();
            dq.push_back(i);
        }

        int ret=INT_MIN;
        for (int i=0; i<n; i++)
            ret=max(ret, dp[i]);
        return ret;
    }
};
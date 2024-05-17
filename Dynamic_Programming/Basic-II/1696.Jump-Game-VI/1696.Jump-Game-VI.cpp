class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>dp(n, INT_MIN/2);
        dp[0]=nums[0];
        deque<int>dq;

        for (int i=0; i<n; i++)
        {
            while (!dq.empty()&&i-dq.front()>k)
                dq.pop_front();
            
            if (!dq.empty()) dp[i]=max(dp[i], dp[dq.front()]+nums[i]);

            while (!dq.empty()&&dp[dq.back()]<=dp[i])
                dq.pop_back();
            dq.push_back(i);
        }
        return dp[n-1];
    }
};
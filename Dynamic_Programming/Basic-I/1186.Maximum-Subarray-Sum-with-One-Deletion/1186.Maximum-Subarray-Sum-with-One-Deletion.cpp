class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n=arr.size();
        arr.insert(arr.begin(), 0);
        vector<vector<int>>dp(n+1, vector<int>(2, INT_MIN/2));

        for (int i=1; i<=n; i++)
        {
            dp[i][0]=max(arr[i], dp[i-1][0]+arr[i]);
            dp[i][1]=max({arr[i], dp[i-1][0], dp[i-1][1]+arr[i]});
        }

        int ret=INT_MIN;
        for (int i=1; i<=n; i++)
            ret=max({ret, dp[i][0], dp[i][1]});
        return ret;
    }
};
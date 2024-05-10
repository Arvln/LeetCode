class Solution {
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        if (a[0]==b[0]) return a[1]>b[1];
        else return a[0]<b[0];
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), cmp);
        int n=envelopes.size();
        vector<int>dp(n, 1);
        for (int i=0; i<n; i++)
            for (int j=0; j<i; j++)
                if (envelopes[i][1]>envelopes[j][1]) dp[i]=max(dp[i], dp[j]+1);
        
        int ret=0;
        for (int i=0; i<n; i++)
            ret=max(ret, dp[i]);
        return ret;
    }
};
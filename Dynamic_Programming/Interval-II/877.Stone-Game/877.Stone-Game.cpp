class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>>dp(n, vector<int>(n, INT_MIN/2));
        for (int i=0; i<n; i++)
            dp[i][i]=piles[i];

        for (int len=2; len<=n; len++)
            for (int i=0, j=i+len-1; j<n; i++, j++)
                dp[i][j]=max(dp[i][j-1]+piles[j], dp[i+1][j]+piles[i]);
        
        int total=accumulate(piles.begin(), piles.end(), 0);
        return dp[0][n-1]>total/2;
    }
};
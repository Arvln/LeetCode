class Solution {
public:
    string minWindow(string S, string T) {
        int m=S.size(), n=T.size();
        S="#"+S;
        T="#"+T;
        vector<vector<int>>dp(m+1, vector<int>(n+1, INT_MAX/2));
        for (int i=0; i<=m; i++)
            dp[i][0]=0;

        for (int i=1; i<=m; i++)
            for (int j=1; j<=n; j++)
                if (S[i]==T[j]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=dp[i-1][j]+1;
        
        int minLen=INT_MAX/2, pos;
        for (int i=0; i<=m; i++)
            if (dp[i][n]<minLen)
            {
                minLen=dp[i][n];
                pos=i;
            }

        if (minLen==INT_MAX/2) return "";
        else return S.substr(pos-minLen+1, minLen);
    }
};
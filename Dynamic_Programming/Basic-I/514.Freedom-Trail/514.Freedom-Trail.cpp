class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int m=ring.size(), n=key.size();
        vector<vector<int>>dp(n, vector<int>(m, INT_MAX/2));
        unordered_map<char, vector<int>>letterToPos;
        for (int i=0; i<m; i++)
            letterToPos[ring[i]].push_back(i);

        for (int pos : letterToPos[key[0]])
            dp[0][pos]=min(dp[0][pos], min(pos, m-pos));

        for (int i=1; i<n; i++)
            for (int pos : letterToPos[key[i]])
                for (int pre_pos : letterToPos[key[i-1]])
                    dp[i][pos]=min(dp[i][pos], dp[i-1][pre_pos]+min(abs(pos-pre_pos), m-abs(pos-pre_pos)));
        
        int ret=INT_MAX;
        for (int pos : letterToPos[key[n-1]])
            ret=min(ret, dp[n-1][pos]);
        return ret+n;
    }
};
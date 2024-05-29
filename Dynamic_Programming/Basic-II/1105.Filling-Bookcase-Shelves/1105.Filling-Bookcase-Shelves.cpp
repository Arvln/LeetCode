class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n=books.size();
        books.insert(books.begin(), {0, 0});
        vector<int>dp(n+1, INT_MAX/2);
        dp[0]=0;

        for (int i=1; i<=n; i++)
        {
            int width=shelfWidth, maxHeight=0;
            for (int j=i; j>0; j--)
            {
                if (width<books[j][0]) break;
                width-=books[j][0];
                maxHeight=max(maxHeight, books[j][1]);
                dp[i]=min(dp[i], dp[j-1]+maxHeight);
            }
        }
        return dp[n];
    }
};
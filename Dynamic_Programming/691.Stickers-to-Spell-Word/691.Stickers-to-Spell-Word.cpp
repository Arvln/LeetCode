class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int n=1<<target.size();
        vector<int>dp(n, INT_MAX/2);
        dp[0]=0;

        for (int status=0; status<n; status++)
            for (string sticker : stickers)
            {
                int newStatus=next(status, sticker, target);
                dp[newStatus]=min(dp[newStatus], dp[status]+1);
            }
        if (dp[n-1]==INT_MAX/2) return -1;
        else return dp[n-1];
    }
    int next(int status, string sticker, string target)
    {
        int n=target.size();
        for (char c : sticker)
            for (int i=0; i<n; i++)
                if (((status>>i)&1)==0&&target[i]==c)
                {
                    status+=1<<i;
                    break;
                }
        return status;
    }
};
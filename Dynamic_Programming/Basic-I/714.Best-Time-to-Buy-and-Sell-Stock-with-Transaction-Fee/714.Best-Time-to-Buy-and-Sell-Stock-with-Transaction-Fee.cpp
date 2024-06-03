class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        prices.insert(prices.begin(), 0);
        vector<int>hold(n+1, INT_MIN/2);
        vector<int>sold(n+1, INT_MIN/2);
        sold[0]=0;

        for (int i=1; i<=n; i++)
        {
            hold[i]=max(hold[i-1], sold[i-1]-prices[i]-fee);
            sold[i]=max(sold[i-1], hold[i-1]+prices[i]);
        }
        return sold[n];
    }
};
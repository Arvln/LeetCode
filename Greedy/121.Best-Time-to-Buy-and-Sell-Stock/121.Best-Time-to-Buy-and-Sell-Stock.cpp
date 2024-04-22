class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cost=INT_MAX, ret=0;
        for (int price : prices)
        {
            ret=max(ret, price-cost);
            cost=min(cost, price);
        }
        return ret;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cost=INT_MAX, ret=0;
        for (int price : prices)
        {
            if (price>cost) ret+=price-cost;
            cost=price;
        }
        return ret;
    }
};
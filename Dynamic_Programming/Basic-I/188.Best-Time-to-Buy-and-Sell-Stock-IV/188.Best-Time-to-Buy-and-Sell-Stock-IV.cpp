class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        if (k>=n/2)
        {
            int cost=INT_MAX, ret=0;
            for (int price : prices)
            {
                if (price>cost) ret+=price-cost;
                cost=price;
            }
            return ret;
        }

        vector<int>hold(k+1, INT_MIN/2);
        vector<int>sold(k+1, INT_MIN/2);
        sold[0]=0;
        auto pre_hold=hold;
        auto pre_sold=sold;
        
        for (int price : prices)
        {
            pre_hold=hold;
            pre_sold=sold;

            for (int j=1; j<=k; j++)
            {
                hold[j]=max(pre_hold[j], pre_sold[j-1]-price);
                sold[j]=max(pre_sold[j], pre_hold[j]+price);
            }
        }

        int ret=0;
        for (int j=1; j<=k; j++)
            ret=max(ret, sold[j]);
        return ret;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>hold(3, INT_MIN/2);
        vector<int>sold(3, INT_MIN/2);
        sold[0]=0;
        auto pre_hold=hold;
        auto pre_sold=sold;

        for (int price : prices)
        {
            pre_hold=hold;
            pre_sold=sold;

            for (int k=1; k<3; k++)
            {
                hold[k]= max(pre_hold[k], pre_sold[k-1]-price);
                sold[k]= max(pre_sold[k], pre_hold[k]+price);
            }
        }
        
        int ret=0;
        for (int k=1; k<3; k++)
            ret=max(ret, sold[k]);
        return ret;
    }
};
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l=0, r=INT_MAX;
        while (l<=r)
        {
            int mid=l+(r-l)/2;

            if (count(weights, mid)>days) l=mid+1;
            else r=mid-1;
        }
        return l;
    }
    int count(vector<int> &weights, int capacity)
    {
        int ret=0, load=0;
        for (int &weight : weights)
        {
            if (weight>capacity) return INT_MAX;

            load-=weight;
            if (load<0)
            {
                load=capacity-weight;
                ret++;
            }
        }
        return ret;
    }
};
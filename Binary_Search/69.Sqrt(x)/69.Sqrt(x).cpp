class Solution {
public:
    int mySqrt(int x) {
        int l=1, r=INT_MAX;
        while (l<=r)
        {
            int mid=l+(r-l)/2;

            if (mid>x/mid) r=mid-1;
            else l=mid+1;
        }
        return r;
    }
};
class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        int l=1, r=1e9*2;
        while (l<=r)
        {
            int mid=l+(r-l)/2;

            if (count(mid, a, b, c)<n) l=mid+1;
            else r=mid-1;
        }
        return l;
    }
    long count(long t, int a, int b, int c)
    {
        return t/a+t/b+t/c-t/lcm(a, b)-t/lcm(b, c)-t/lcm(a, c)+t/lcm(a, lcm(b, c));
    }
    long lcm(long a, long b)
    {
        return a*b/gcd(a, b);
    }
    long gcd(long a, long b)
    {
        if (b==0) return a;
        else return gcd(b, a%b);
    }
};
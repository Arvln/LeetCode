class Solution {
public:
    double myPow(double x, long n) {
        if (n==0) return 1;
        else if (n<0) return 1/myPow(x, -n);
        else if (n%2==1) return x*myPow(x, n-1);
        else
        {
            double result=myPow(x, n/2);
            return result*result;
        }
    }
};
class Solution {
public:
    int reverse(int x) {
        if (x==INT_MIN) return 0;

        bool pos=x>=0;
        x=abs(x);
        int ret=0;
        while (x>0)
        {
            if (pos&&ret>INT_MAX/10) return 0;
            else if (!pos&&-ret<INT_MIN/10) return 0;

            ret*=10;
            ret+=x%10;
            x/=10;
        }

        if (pos) return ret;
        else return -ret;
    }
};
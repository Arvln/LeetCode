class Solution {
public:
    int findNthDigit(int n) {
        int digit=1;
        long long base=1;
        while (n>9*digit*base)
        {
            n-=9*digit*base;
            digit+=1;
            base*=10;
        }

        long long target=(n-1)/digit+base;
        int pos=(n-1)%digit;
        return (to_string(target)[pos])-'0';
    }
};
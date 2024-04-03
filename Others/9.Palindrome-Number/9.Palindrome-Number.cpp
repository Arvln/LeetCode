class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;

        long num=x;
        long reversed=0;
        while (num>0)
        {
            reversed=reversed*10+num%10;
            num/=10;
        }
        return x==reversed;
    }
};
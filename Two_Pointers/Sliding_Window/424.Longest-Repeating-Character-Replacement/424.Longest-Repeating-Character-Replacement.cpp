class Solution {
public:
    int characterReplacement(string s, int k) {
        int ret=0;
        for (char c='A'; c<='Z'; c++)
            ret=max(ret, maxLenWithLimit(s, c, k));
        return ret;
    }
    int maxLenWithLimit(string &s, char &c, int k)
    {
        int l=0, r=0, ret=0;
        while (r<s.size())
        {
            k-=s[r]!=c;
            r++;

            while (l<r&&k<0)
            {
                k+=s[l]!=c;
                l++;
            }
            ret=max(ret, r-l);
        }
        return ret;
    }
};
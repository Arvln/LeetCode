class Solution {
public:
    int strStr(string haystack, string needle) {
        int Q=1e9+7;
        int R=256;
        long RL=1;
        long target=0;
        for (char c : needle)
        {
            target=(target*R%Q+c)%Q;
            RL=RL*R%Q;
        }
        
        int l=0, r=0;
        long cur=0;
        while (r<haystack.size())
        {
            cur=(cur*R%Q+haystack[r])%Q;
            r++;

            if (r-l>needle.size())
            {
                cur=(cur-haystack[l]*RL%Q+Q)%Q;
                l++;
            }

            if (cur==target&&haystack.substr(l, r-l)==needle) return l;
        }
        return -1;
    }
};
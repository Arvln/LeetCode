class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>Map; // char->count
        int l=0, r=0, ret=0;
        while (r<s.size())
        {
            char c=s[r];
            Map[c]++;
            r++;

            while (l<r&&Map[c]>1)
            {
                Map[s[l]]--;
                l++;
            }
            ret=max(ret, r-l);
        }
        return ret;
    }
};
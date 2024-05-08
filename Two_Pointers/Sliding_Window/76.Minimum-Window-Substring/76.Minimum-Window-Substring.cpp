class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int>window, target;
        for (char c : t)
            target[c]++;

        int l=0, r=0, minLen=INT_MAX, valid=0, count=target.size();
        string ret;
        while (r<s.size())
        {
            window[s[r]]++;
            if (window[s[r]]==target[s[r]]) valid++;
            r++;

            while (l<r&&window[s[l]]>target[s[l]])
            {
                window[s[l]]--;
                l++;
            }

            if (valid==count&&r-l<minLen)
            {
                minLen=r-l;
                ret=s.substr(l, r-l);
            }
        }

        if (minLen==INT_MAX) return "";
        else return ret;
    }
};
class Solution {
public:
    int longestSubstring(string s, int k) {
        int ret=0;
        for (int i=1; i<=26; i++)
            ret=max(ret, maxLenWithLimit(s, i, k));
        return ret;
    }
    int maxLenWithLimit(string &s, int limit, int k)
    {
        unordered_map<char, int>Map; // char->count
        int l=0, r=0, valid=0, ret=0;
        while (r<s.size())
        {
            Map[s[r]]++;
            if (Map[s[r]]==k) valid++;
            r++;

            while (Map.size()>limit)
            {
                if (Map[s[l]]==k) valid--;
                Map[s[l]]--;
                if (Map[s[l]]==0) Map.erase(s[l]);
                l++;
            }
            if (Map.size()==limit&&valid==limit) ret=max(ret, r-l);
        }
        return ret;
    }
};
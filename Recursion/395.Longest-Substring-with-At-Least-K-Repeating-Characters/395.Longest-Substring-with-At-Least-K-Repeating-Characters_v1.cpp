class Solution {
public:
    int longestSubstring(string s, int k) {
        unordered_map<char, int>Map; // char->count
        for (char c : s)
            Map[c]++;
        
        int flag=0;
        for (auto &[_, count] : Map)
            if (count<k)
            {
                flag=1;
                break;
            }
        
        if (flag==0) return s.size();

        int ret=0;
        for (int i=0; i<s.size(); i++)
        {
            if (Map[s[i]]<k) continue;

            int j=i;
            while (i<s.size()&&Map[s[i]]>=k)
                i++;
            ret=max(ret, longestSubstring(s.substr(j, i-j), k));
        }
        return ret;
    }
};
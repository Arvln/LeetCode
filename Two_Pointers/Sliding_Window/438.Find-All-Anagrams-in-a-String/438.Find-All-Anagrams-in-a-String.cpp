class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>state(26);
        vector<int>target(26);
        for (char c : p)
            target[c-'a']++;
        
        vector<int>rets;
        int l=0, r=0;
        while (r<s.size())
        {
            state[s[r]-'a']++;
            r++;

            if (r-l>p.size())
            {
                state[s[l]-'a']--;
                l++;
            }
            if (r-l==p.size()&&state==target)
                rets.push_back(l);
        }
        return rets;
    }
};
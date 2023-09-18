class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ret, window(26, 0), records(26, 0);
        for (char c : p)
            records[c-'a']+=1;
        
        int left=0, right=0;
        while (right<s.size())
        {
            if (records[s[right]-'a'])
                window[s[right]-'a']+=1;
            right++;

            if (right-left==p.size())
            {
                if (window==records)
                    ret.push_back(left);
                
                if (records[s[left]-'a'])
                     window[s[left]-'a']-=1;
                left++;
            }
        }
        return ret;
    }
};
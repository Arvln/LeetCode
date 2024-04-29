class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>target(26, 0);
        for (char c : s1)
            target[c-'a']++;
        vector<int>window(26, 0);
        int l=0, r=0;
        while (r<s2.size())
        {
            window[s2[r]-'a']++;
            r++;

            if (r-l>s1.size())
            {
                window[s2[l]-'a']--;
                l++;
            }
            if (r-l==s1.size()&&window==target) return true;
        }
        return false;
    }
};
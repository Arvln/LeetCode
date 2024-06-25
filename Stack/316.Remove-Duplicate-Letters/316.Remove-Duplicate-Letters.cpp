class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int>Map; // char->count
        for (char c : s)
            Map[c]++;
        
        unordered_set<char>used;
        string ret;
        for (int i=0; i<s.size(); i++)
        {
            Map[s[i]]--;
            if (used.find(s[i])!=used.end()) continue;

            while (!ret.empty()&&ret.back()>s[i]&&Map[ret.back()]>0)
            {
                used.erase(ret.back());
                ret.pop_back();
            }

            used.insert(s[i]);
            ret.push_back(s[i]);
        }
        return ret;
    }
};
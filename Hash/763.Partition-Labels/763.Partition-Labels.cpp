class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int>Map; // char->count
        for (char c : s)
            Map[c]++;
        
        unordered_set<char>window;
        vector<int>ret;
        int i=0;
        while (i<s.size())
        {
            int i0=i;
            window.insert(s[i]);
            while (i<s.size()&&!window.empty())
            {
                window.insert(s[i]);
                Map[s[i]]--;
                if (Map[s[i]]==0) window.erase(s[i]);
                i++;
            }
            ret.push_back(i-i0);
        }
        return ret;
    }
};
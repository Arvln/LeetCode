class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int>Map; // char->count
        for (char c : s)
            Map[c]++;
        for (char c : t)
        {
            Map[c]--;
            if (Map[c]==0) Map.erase(c);
        }
        return Map.empty();
    }
};
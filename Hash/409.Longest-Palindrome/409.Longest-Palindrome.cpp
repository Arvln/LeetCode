class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int>Map; // char->count
        for (char c : s)
            Map[c]++;
        
        int pair=0, single=0;
        for (auto &[_, count] : Map)
        {
            if (count%2==1) single=1;
            pair+=count/2;
        }
        return pair*2+single;
    }
};
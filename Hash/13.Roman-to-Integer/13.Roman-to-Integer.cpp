class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int>Map{
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        int ret=Map[s[0]];
        for (int i=1; i<s.size(); i++)
        {
            ret+=Map[s[i]];
            if (Map[s[i]]>Map[s[i-1]]) ret-=2*Map[s[i-1]];
        }
        return ret;
    }
};
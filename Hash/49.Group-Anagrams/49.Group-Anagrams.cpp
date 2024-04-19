class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>Map; // id->anagrams
        for (string &str : strs)
        {
            string s=str;
            sort(s.begin(), s.end());
            Map[s].push_back(str);
        }
        vector<vector<string>>rets;
        for (auto &[_, group] : Map)
            rets.push_back(group);
        return rets;
    }
};
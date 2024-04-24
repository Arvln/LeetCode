class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int>Map; // char->count;
        for (char c : s)
            Map[c]++;
        priority_queue<pair<int, char>>pq;
        for (auto &c : Map)
            pq.push({c.second, c.first});
        
        string ret;
        while (!pq.empty())
        {
            auto cur=pq.top();
            pq.pop();

            ret+=string(cur.first, cur.second);
        }
        return ret;
    }
};
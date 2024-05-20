class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int>Map; // {char, count}
        for (char c : s)
            Map[c]++;
        
        priority_queue<pair<int, char>>pq; // {count, char}
        for (auto &[c, count] : Map)
            pq.push({count, c});
        
        string ret;
        while (!pq.empty())
        {
            if (pq.size()==1)
            {
                if (pq.top().first>1) return "";
                ret.push_back(pq.top().second);
                pq.pop();
            }
            else
            {
                auto [count1, c1]=pq.top();
                pq.pop();
                auto [count2, c2]=pq.top();
                pq.pop();

                ret.push_back(c1);
                ret.push_back(c2);

                if (count1>1) pq.push({count1-1, c1});
                if (count2>1) pq.push({count2-1, c2});
            }
        }
        return ret;
    }
};
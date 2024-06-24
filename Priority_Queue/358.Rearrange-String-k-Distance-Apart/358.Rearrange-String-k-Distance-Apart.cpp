class Solution {
public:
    string rearrangeString(string &s, int k) {
        unordered_map<char, int>Map; // char->freq
        for (char c : s)
            Map[c]++;

        priority_queue<pair<int, char>>pq; // {freq, char}
        for (auto &[c, freq] : Map)
            pq.push({freq, c});

        string ret;
        while (!pq.empty())
        {
            vector<pair<int, char>>temp;
            int n=min((int)pq.size(), k);
            for (int i=0; i<n; i++)
            {
                auto [freq, c]=pq.top();
                pq.pop();

                ret.push_back(c);
                if (freq>1) temp.push_back({freq-1, c});
            }

            if (n<k&&!temp.empty()) return "";

            for (auto &item : temp)
                pq.push(item);
        }
        return ret;
    }
};
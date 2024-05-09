using PIS=pair<int, string>;
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int>Map; // word->freq
        for (string &word : words)
            Map[word]++;

        auto cmp=[](PIS &a, PIS &b)
        {
            if (a.first==b.first) return a.second>b.second;
            else return a.first<b.first;
        };
        priority_queue<PIS, vector<PIS>, decltype(cmp)>pq;
        for (auto &[word, freq] : Map)
            pq.push({freq, word});

        vector<string>ret;
        while (ret.size()<k)
        {
            auto [_, word]=pq.top();
            pq.pop();
            ret.push_back(word);
        }
        return ret;
    }
};
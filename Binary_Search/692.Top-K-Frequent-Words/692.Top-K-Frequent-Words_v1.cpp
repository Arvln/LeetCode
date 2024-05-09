class Solution {
    unordered_map<string, int>Map; // word->freq
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        for (string &word : words)
            Map[word]++;
        
        int l=1, r=words.size();
        while (l<=r)
        {
            int mid=l+(r-l)/2;

            if (count(mid)>=k) l=mid+1;
            else r=mid-1;
        }

        vector<string>ret;
        for (auto &[word, freq] : Map)
            if (freq>=r) ret.push_back(word);
        
        auto cmp=[&](string &a, string &b)
        {
            if (Map[a]==Map[b]) return a<b;
            else return Map[a]>Map[b];
        };
        sort(ret.begin(), ret.end(), cmp);
        while (ret.size()>k)
            ret.pop_back();
        return ret;
    }
    int count(int freq)
    {
        int ret=0;
        for (auto &x : Map)
            ret+=x.second>=freq;
        return ret;
    }
};
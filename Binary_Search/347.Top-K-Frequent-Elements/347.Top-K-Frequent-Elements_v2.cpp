class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>Map; // num->freq
        for (int num : nums)
            Map[num]++;
        
        priority_queue<pair<int, int>>pq; // {freq, num}
        for (auto &[num, freq] : Map)
            pq.push({freq, num});
        
        vector<int>ret;
        while (ret.size()<k)
        {
            ret.push_back(pq.top().second);
            pq.pop();
        }
        return ret;
    }
};
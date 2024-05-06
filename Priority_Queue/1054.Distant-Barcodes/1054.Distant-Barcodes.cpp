class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int>Map; // {code, count}
        for (int code : barcodes)
            Map[code]++;
        
        priority_queue<pair<int, int>>pq; // {count, code}
        for (auto &[code, count] : Map)
            pq.push({count, code});
        vector<int>ret;
        while (!pq.empty())
        {
            if (pq.size()==1)
            {
                ret.push_back(pq.top().second);
                pq.pop();
            }
            else
            {
                auto [count1, code1]=pq.top();
                pq.pop();
                auto [count2, code2]=pq.top();
                pq.pop();

                ret.push_back(code1);
                ret.push_back(code2);

                if (count1>1) pq.push({count1-1, code1});
                if (count2>1) pq.push({count2-1, code2});
            }
        }
        return ret;
    }
};
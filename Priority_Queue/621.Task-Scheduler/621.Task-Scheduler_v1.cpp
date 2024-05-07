class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        n++;
        unordered_map<char, int>Map; // char->count
        for (char c : tasks)
            Map[c]++;
        priority_queue<int>pq;
        for (auto &[_, freq] : Map)
            pq.push(freq);
        
        int ret=0;
        while (!pq.empty())
        {
            int k=min(n, (int)pq.size());
            vector<int>temp;
            for (int i=0; i<k; i++)
            {
                int freq=pq.top();
                pq.pop();

                freq--;
                if (freq>0) temp.push_back(freq);
            }

            if (temp.empty()) ret+=k;
            else ret+=n;

            for (int freq : temp)
                pq.push(freq);
        }
        return ret;
    }
};
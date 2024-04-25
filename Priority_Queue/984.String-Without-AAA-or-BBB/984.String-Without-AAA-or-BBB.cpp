class Solution {
public:
    string strWithout3a3b(int a, int b) {
        priority_queue<pair<int, char>>pq;
        pq.push({a, 'a'});
        pq.push({b, 'b'});
        string ret;
        while (!pq.empty())
        {
            if (pq.size()==1)
            {
                auto [count, c]=pq.top();
                pq.pop();
                ret+=string(count, c);
            }
            else
            {
                auto c1=pq.top();
                pq.pop();
                auto c2=pq.top();
                pq.pop();

                int k=min(c1.first-c2.first+1, 2);
                for (int i=0; i<k; i++)
                    ret.push_back(c1.second);
                ret.push_back(c2.second);

                if (c1.first>k) pq.push({c1.first-k, c1.second});
                if (c2.first>1) pq.push({c2.first-1, c2.second});
            }
        }
        return ret;
    }
};
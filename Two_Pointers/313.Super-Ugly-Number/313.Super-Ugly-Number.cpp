typedef pair<long, int> PLI;
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k=primes.size();
        vector<int> pointers(k, 0);
        vector<long> ret{1};
        priority_queue<PLI, vector<PLI>, greater<>> pq;
        for (int i=0; i<k; i++)
            pq.push({ret[pointers[i]]*primes[i], i});
        for (int p=0; p<n-1; p++)
        {
            long cur=pq.top().first;
            ret.push_back(cur);

            while (!pq.empty()&&cur==pq.top().first)
            {
                int i=pq.top().second;
                pq.pop();
                pointers[i]+=1;
                pq.push({ret[pointers[i]]*primes[i], i});
            }
        }
        return ret.back();
    }
};
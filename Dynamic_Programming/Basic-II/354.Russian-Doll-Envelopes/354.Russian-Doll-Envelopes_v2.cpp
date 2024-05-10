class Solution {
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        if (a[0]==b[0]) return a[1]>b[1];
        else return a[0]<b[0];
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int>q;
        for (auto envelope : envelopes)
        {
            auto iter=lower_bound(q.begin(), q.end(), envelope[1]);

            if (iter==q.end()) q.push_back(envelope[1]);
            else *iter=envelope[1];
        }
        return q.size();
    }
};
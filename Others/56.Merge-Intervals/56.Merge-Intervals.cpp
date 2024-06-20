using PII=pair<int, int>;
class Solution {
    static bool cmp(PII &a, PII &b)
    {
        if (a.first==b.first) return a.second>b.second;
        else return a.first<b.first;
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<PII>diff;
        for (auto &interval : intervals)
        {
            diff.push_back({interval[0], 1});
            diff.push_back({interval[1], -1});
        }
        sort(diff.begin(), diff.end(), cmp);

        int count=0;
        vector<vector<int>>ret;
        for (auto &[point, shift] : diff)
        {
            count+=shift;

            if (count==1&&shift==1) ret.push_back({point});
            if (count==0&&shift==-1) ret.back().push_back(point);
        }
        return ret;
    }
};
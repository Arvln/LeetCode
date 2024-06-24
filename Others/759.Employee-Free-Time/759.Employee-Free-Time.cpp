using PII=pair<int, int>;
class Solution {
    static bool cmp(PII &a, PII &b)
    {
        if (a.first==b.first) return a.second>b.second;
        else return a.first<b.first;
    }
public:
    vector<Interval> employeeFreeTime(vector<vector<int>> &schedule) {
        vector<PII>diff;
        for (auto &intervals : schedule)
            for (auto interval : intervals)
            {
                diff.push_back({interval.start, 1});
                diff.push_back({interval.end, -1});
            }
        sort(diff.begin(), diff.end(), cmp);

        int count=0;
        vector<Interval>ret;
        for (auto &[time, shift] : diff)
        {
            count+=shift;

            if (count==0&&shift==-1) ret.push_back(new Interval(time, INT_MAX));
            if (count==1&&shift==1&&!ret.empty()) ret.back().end=time;
        }
        ret.pop_back();
        return ret;
    }
};
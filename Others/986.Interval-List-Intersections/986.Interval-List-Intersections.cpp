using PII=pair<int, int>;
class Solution {
    static bool cmp(PII &a, PII &b)
    {
        if (a.first==b.first) return a.second>b.second;
        else return a.first<b.first;
    }
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<PII>diff;
        for (auto &list : firstList)
        {
            diff.push_back({list[0], 1});
            diff.push_back({list[1], -1});
        }
        for (auto &list : secondList)
        {
            diff.push_back({list[0], 1});
            diff.push_back({list[1], -1});
        }
        sort(diff.begin(), diff.end(), cmp);

        int count=0;
        vector<vector<int>>ret;
        for (auto &[time, shift] : diff)
        {
            count+=shift;

            if (count==2&&shift==1) ret.push_back({time});
            if (count==1&&shift==-1) ret.back().push_back(time);
        }
        return ret;
    }
};
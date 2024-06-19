class Solution {
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        if (a[0]==b[0]) return a[1]>b[1];
        else return a[0]<b[0];
    }
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);

        int ret=0;
        for (int i=0; i<intervals.size();)
        {
            int end=intervals[i][1];
            while (i<intervals.size()&&intervals[i][1]<=end)
                i++;
            ret++;
        }
        return ret;
    }
};
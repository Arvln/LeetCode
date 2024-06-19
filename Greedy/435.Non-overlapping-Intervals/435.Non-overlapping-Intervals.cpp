class Solution {
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[1]<b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);

        int n=intervals.size(), overlap=0;
        for (int i=0; i<n;)
        {
            int end=intervals[i][1];
            while (i<n&&intervals[i][0]<end)
                i++;
            overlap++;
        }
        return n-overlap;
    }
};
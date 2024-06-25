class Solution {
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[1]<b[1];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        sort(points.begin(), points.end(), cmp);

        int i=0, ret=0;
        while (i<n)
        {
            int end=points[i][1];
            while (i<n&&points[i][0]<=end)
                i++;
            ret++;
        }
        return ret;
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int l=0, r=2*1e8;
        while (l<=r)
        {
            int mid=l+(r-l)/2;

            if (count(points, mid)<k) l=mid+1;
            else r=mid-1;
        }

        vector<vector<int>>ret;
        for (auto &point : points)
        {
            int x=point[0], y=point[1];
            if (x*x+y*y<=l) ret.push_back(point);
        }
        return ret;
    }
    int count(vector<vector<int>> &points, int t)
    {
        int ret=0;
        for (auto &point : points)
        {
            int x=point[0], y=point[1];
            ret+=x*x+y*y<=t;
        }
        return ret;
    }
};
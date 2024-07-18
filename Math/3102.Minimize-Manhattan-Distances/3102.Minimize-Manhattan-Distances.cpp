class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        vector<multiset<int>>arr(4);
        for (auto &point : points)
        {
            int x=point[0], y=point[1];
            arr[0].insert(x+y);
            arr[1].insert(x-y);
            arr[2].insert(-x+y);
            arr[3].insert(-x-y);
        }

        int ret=INT_MAX;
        for (auto &point : points)
        {
            int x=point[0], y=point[1];
            arr[0].erase(arr[0].find(x+y));
            arr[1].erase(arr[1].find(x-y));
            arr[2].erase(arr[2].find(-x+y));
            arr[3].erase(arr[3].find(-x-y));

            int maxDis=0;
            maxDis=max(maxDis, *prev(arr[0].end()) - *arr[0].begin());
            maxDis=max(maxDis, *prev(arr[1].end()) - *arr[1].begin());
            maxDis=max(maxDis, *prev(arr[2].end()) - *arr[2].begin());
            maxDis=max(maxDis, *prev(arr[3].end()) - *arr[3].begin());
            ret=min(ret, maxDis);

            arr[0].insert(x+y);
            arr[1].insert(x-y);
            arr[2].insert(-x+y);
            arr[3].insert(-x-y);
        }
        return ret;
    }
};
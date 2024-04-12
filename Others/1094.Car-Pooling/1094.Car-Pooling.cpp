class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int, int>>diff;
        for (auto &trip : trips)
        {
            int num=trip[0], from=trip[1], to=trip[2];
            diff.push_back({from, num});
            diff.push_back({to, -num});
        }
        sort(diff.begin(), diff.end());
        int total=0;
        for (auto &[_, shift] : diff)
        {
            if (total+shift>capacity) return false;
            total+=shift;
        }
        return true;
    }
};
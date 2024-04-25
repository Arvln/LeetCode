class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<pair<int, int>>diff;
        for (auto &interval : intervals)
        {
            diff.push_back({interval[0], 1});
            diff.push_back({interval[1], -1});
        }
        sort(diff.begin(), diff.end());
        int sum=0, ret=0;
        for (auto &[_, shift] : diff)
        {
            sum+=shift;
            ret=max(ret, sum);
        }
        return ret;
    }
};
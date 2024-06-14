class Solution {
public:
    bool canAttendMeetings(vector<vector<int>> &intervals) {
        vector<pair<int, int>>times; // {time, increment}
        for (auto &interval : intervals)
        {
            times.push_back({interval[0], 1});
            times.push_back({interval[1], -1});
        }
        sort(times.begin(), times.end());

        int count=0;
        for (auto &[_, shift] : times)
        {
            count+=shift;
            if (count>1) return false;
        }
        return true;
    }
};
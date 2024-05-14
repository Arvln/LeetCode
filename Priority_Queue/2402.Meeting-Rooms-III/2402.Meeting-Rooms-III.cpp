using PLI=pair<long, int>; // {available time, room}
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<int, vector<int>, greater<>>free;
        priority_queue<PLI, vector<PLI>, greater<>>used;

        for (int i=0; i<n; i++)
            free.push(i);

        sort(meetings.begin(), meetings.end());
        vector<int>count(n, 0);
        for (int i=0; i<meetings.size(); i++)
        {
            int start=meetings[i][0], end=meetings[i][1];

            while (!used.empty()&&used.top().first<=start)
            {
                free.push(used.top().second);
                used.pop();
            }

            if (!free.empty())
            {
                int room=free.top();
                free.pop();
                count[room]++;
                used.push({end, room});
            }
            else
            {
                auto [time, room]=used.top();
                used.pop();
                count[room]++;
                used.push({time+end-start, room});
            }
        }
        return max_element(count.begin(), count.end())-count.begin();
    }
};
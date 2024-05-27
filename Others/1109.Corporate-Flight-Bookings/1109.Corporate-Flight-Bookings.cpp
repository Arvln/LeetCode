class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>diff(n, 0);
        for (auto &flight : bookings)
        {
            int first=flight[0], last=flight[1], seats=flight[2];
            diff[first-1]+=seats;
            if (last<n) diff[last]-=seats;
        }

        int sum=0;
        vector<int>ret;
        for (int i=0; i<n; i++)
        {
            sum+=diff[i];
            ret.push_back(sum);
        }
        return ret;
    }
};
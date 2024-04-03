class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long total=accumulate(milestones.begin(), milestones.end(), 0LL);
        long long maximum=*max_element(milestones.begin(), milestones.end());

        if (maximum*2>total) return (total-maximum)*2+1;
        else return total;
    }
};
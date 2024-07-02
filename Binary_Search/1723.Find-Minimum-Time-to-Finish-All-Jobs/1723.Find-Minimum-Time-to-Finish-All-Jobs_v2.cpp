class Solution {
    vector<int>jobs, times;
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        sort(jobs.begin(), jobs.end());
        reverse(jobs.begin(), jobs.end());
        this->jobs=jobs;
        times.resize(k);

        int l=1, r=accumulate(jobs.begin(), jobs.end(), 0);
        while (l<=r)
        {
            int mid=l+(r-l)/2;

            if (dfs(mid, 0)) r=mid-1;
            else l=mid+1;
            fill(times.begin(), times.end(), 0);
        }
        return l;
    }
    bool dfs(int upper, int cur)
    {
        if (cur==jobs.size()) return true;
        
        int last=-1;
        for (int i=0; i<times.size(); i++)
        {
            if (times[i]+jobs[cur]>upper) continue;
            if (last==times[i]) continue;
            last=times[i];

            times[i]+=jobs[cur];
            if (dfs(upper, cur+1)) return true;
            times[i]-=jobs[cur];
        }
        return false;
    }
};
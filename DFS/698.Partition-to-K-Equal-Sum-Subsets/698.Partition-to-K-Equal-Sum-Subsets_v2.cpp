class Solution {
    int n, k, total;
    int sum[17];
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        total=accumulate(nums.begin(), nums.end(), 0);
        if (total%k!=0) return false;

        this->n=nums.size();
        this->k=k;
        sort(nums.rbegin(), nums.rend());
        return dfs(nums, 0);
    }
    bool dfs(vector<int> &nums, int cur)
    {
        if (cur==n) return true;
        
        int last=-1;
        for (int i=0; i<k; i++)
        {
            if (sum[i]+nums[cur]>total/k) continue;
            if (last==sum[i]) continue;
            last=sum[i];

            sum[i]+=nums[cur];
            if (dfs(nums, cur+1)) return true;
            sum[i]-=nums[cur];
        }
        return false;
    }
};
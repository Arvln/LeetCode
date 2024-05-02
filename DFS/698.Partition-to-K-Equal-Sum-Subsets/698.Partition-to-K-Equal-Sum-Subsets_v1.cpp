class Solution {
    vector<int>visited;
    int n, k, total;
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        total=accumulate(nums.begin(), nums.end(), 0);
        if (total%k!=0) return false;

        this->n=nums.size();
        this->k=k;
        visited=vector<int>(n, 0);
        sort(nums.rbegin(), nums.rend());
        return dfs(nums, 0, 0, 0);
    }
    bool dfs(vector<int> &nums, int cur, int count, int sum)
    {
        if (count==k) return true;
        else if (sum==total/k) return dfs(nums, 0, count+1, 0);

        int last=-1;
        for (int i=cur; i<n; i++)
        {
            if (sum+nums[i]>total/k) continue;
            if (visited[i]==1) continue;
            if (nums[i]==last) continue;
            last=nums[i];

            visited[i]=1;
            if (dfs(nums, i+1, count, sum+nums[i])) return true;
            visited[i]=0;
        }
        return false;
    }
};
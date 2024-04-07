class Solution {
    int total, k;
    vector<int>visited;
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        total=accumulate(nums.begin(), nums.end(), 0);
        if (total%k!=0) return false;
        this->k=k;
        sort(nums.begin(), nums.end());
        visited=vector<int>(nums.size());
        return dfs(nums, 0, 0, 0);
    }
    bool dfs(vector<int>&nums, int cur, int sum, int count)
    {
        if (count==k) return true;
        else if (sum==total/k) return dfs(nums, 0, 0, count+1);

        int last=-1;
        for (int i=cur; i<nums.size(); i++)
        {
            if (sum+nums[i]>total/k) continue;
            if (visited[i]==1) continue;
            if (last==nums[i]) continue;
            last=nums[i];

            visited[i]=1;
            if (dfs(nums, cur+1, sum+nums[i], count))
                return true;
            visited[i]=0;
        }
        return false;
    }
};
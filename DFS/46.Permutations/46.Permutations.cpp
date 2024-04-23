class Solution {
    vector<vector<int>>rets;
    vector<int>path, used;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        used=vector<int>(nums.size(), 0);
        dfs(nums);
        return rets;
    }
    void dfs(vector<int> &nums)
    {
        int n=nums.size();
        if (path.size()==n)
        {
            rets.push_back(path);
            return;
        }

        for (int i=0; i<n; i++)
        {
            if (used[i]==1) continue;

            path.push_back(nums[i]);
            used[i]=1;
            dfs(nums);
            path.pop_back();
            used[i]=0;
        }
    }
};
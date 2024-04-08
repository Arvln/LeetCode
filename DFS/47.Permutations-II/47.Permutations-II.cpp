class Solution {
    vector<vector<int>>rets;
    vector<int>path, visited;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        visited=vector<int>(nums.size());
        dfs(nums);
        return rets;
    }
    void dfs(vector<int>&nums)
    {
        if (path.size()==nums.size())
        {
            rets.push_back(path);
            return;
        }

        int last=-11;
        for (int i=0; i<nums.size(); i++)
        {
            if (visited[i]==1) continue;
            if (last==nums[i]) continue;
            last=nums[i];

            visited[i]=1;
            path.push_back(nums[i]);
            dfs(nums);
            visited[i]=0;
            path.pop_back();
        }
    }
};
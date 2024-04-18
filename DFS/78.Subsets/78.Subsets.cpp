class Solution {
    vector<vector<int>>rets;
    vector<int>path;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return rets;
    }
    void dfs(vector<int>&nums, int i)
    {
        rets.push_back(path);

        for (int j=i; j<nums.size(); j++)
        {
            path.push_back(nums[j]);
            dfs(nums, j+1);
            path.pop_back();
        }
    }
};
class Solution {
    vector<vector<int>>ret;
    vector<int>path;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, 0, target);
        return ret;
    }
    void dfs(vector<int> &nums, int cur, int target)
    {
        if (target==0)
        {
            ret.push_back(path);
            return;
        }

        for (int i=cur; i<nums.size(); i++)
        {
            if (target<nums[i]) continue;

            path.push_back(nums[i]);
            dfs(nums, i, target-nums[i]);
            path.pop_back();
        }
    }
};
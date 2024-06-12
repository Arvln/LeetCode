class Solution {
    vector<vector<int>>ret;
    vector<int>path;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target);
        return ret;
    }
    void dfs(vector<int> &nums, int cur, int target)
    {
        if (target==0) ret.push_back(path);

        int last=0;
        for (int i=cur; i<nums.size(); i++)
        {
            if (target<nums[i]) continue;
            else if (last==nums[i]) continue;
            last=nums[i];

            path.push_back(nums[i]);
            dfs(nums, i+1, target-nums[i]);
            path.pop_back();
        }
    }
};
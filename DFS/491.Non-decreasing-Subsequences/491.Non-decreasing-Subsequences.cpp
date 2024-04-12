class Solution {
    vector<vector<int>>rets;
    vector<int>path;
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        dfs(nums, 0);
        return rets;
    }
    void dfs(vector<int>&nums, int start)
    {
        if (path.size()>1) rets.push_back(path);

        unordered_set<int>visited;
        for (int i=start; i<nums.size(); i++)
        {
            if (!path.empty()&&path.back()>nums[i]) continue;
            if (visited.find(nums[i])!=visited.end()) continue;
            visited.insert(nums[i]);

            path.push_back(nums[i]);
            dfs(nums, i+1);
            path.pop_back();
        }
    }
};
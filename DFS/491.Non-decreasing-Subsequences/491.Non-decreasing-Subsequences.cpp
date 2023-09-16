class Solution {
    vector<vector<int>>ret;
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int>ans;
        dfs(nums, ans, 0);
        return ret;
    }
    void dfs(vector<int>& nums, vector<int>& ans, int start)
    {
        if (ans.size()>1)
            ret.push_back(ans);

        unordered_set<int>visited;
        for (int i=start; i<nums.size(); i++)
        {
            if (visited.find(nums[i])!=visited.end()) continue;
            if (!ans.empty()&&ans.back()>nums[i]) continue;

            visited.insert(nums[i]);
            ans.push_back(nums[i]);
            dfs(nums, ans, i+1);
            ans.pop_back();
        }
    }
};
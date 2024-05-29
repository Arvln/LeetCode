class Solution {
    vector<vector<int>>rets;
    vector<int>path;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return rets;
    }
    void dfs(vector<int> &nums, int cur)
    {
        rets.push_back(path);

        int last=-11;
        for (int i=cur; i<nums.size(); i++)
        {
            if (last==nums[i]) continue;
            last=nums[i];

            path.push_back(nums[i]);
            dfs(nums, i+1);
            path.pop_back();
        }
    }
};
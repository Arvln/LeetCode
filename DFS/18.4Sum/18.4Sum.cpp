class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return dfs(nums, 4, 0, target);
    }
    vector<vector<int>> dfs(vector<int> &nums, int n, int i, long target)
    {
        vector<vector<int>>rets;

        if (n==2)
        {
            int j=nums.size()-1;
            while (i<j)
            {
                int sum=nums[i]+nums[j];

                if (sum<target) i++;
                else if (sum>target) j--;
                else
                {
                    rets.push_back({nums[i], nums[j]});
                    while (i+1<nums.size()&&nums[i]==nums[i+1]) i++;
                    while (j-1>i&&nums[j]==nums[j-1]) j--;
                    i++, j--;
                }
            }
        }
        else
        {
            int last=1e9+7;
            for (int k=i; k<nums.size(); k++)
            {
                if (nums[k]==last) continue;
                last=nums[k];

                for (vector<int> ret : dfs(nums, n-1, k+1, target-nums[k]))
                {
                    ret.push_back(nums[k]);
                    rets.push_back(ret);
                }
            }
        }
        return rets;
    }
};
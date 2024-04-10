class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return dfs(nums, 3, 0, 0);
    }
    vector<vector<int>> dfs(vector<int>&nums, int n, int i, long target)
    {
        vector<vector<int>>rets;
        if (n==2)
        {
            int j=nums.size()-1;
            while (i<j)
            {
                long sum=nums[i]+nums[j];
                if (sum<target) i++;
                else if (sum>target) j--;
                else
                {
                    rets.push_back({nums[i], nums[j]});
                    while (i+1<j&&nums[i]==nums[i+1]) i++;
                    while (j-1>i&&nums[j]==nums[j-1]) j--;
                    i++, j--;
                }
            }
        }
        else
        {
            int last=1e6;
            for (int k=i; k<nums.size(); k++)
            {
                if (last==nums[k]) continue;
                last=nums[k];
                for (vector<int>ret : dfs(nums, n-1, k+1, target-nums[k]))
                {
                    ret.push_back(nums[k]);
                    rets.push_back(ret);
                }
            }
        }
        return rets;
    }
};
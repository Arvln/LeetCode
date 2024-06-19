class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>q;
        for (int i=0; i<nums.size(); i++)
        {
            if (q.empty()||q.back()<nums[i]) q.push_back(nums[i]);
            else
            {
                auto iter=lower_bound(q.begin(), q.end(), nums[i]);
                *iter=nums[i];
            }
        }
        return q.size();
    }
};
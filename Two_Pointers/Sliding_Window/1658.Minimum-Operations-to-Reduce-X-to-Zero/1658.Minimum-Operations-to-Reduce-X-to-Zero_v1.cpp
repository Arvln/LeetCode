class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        for (int i=0; i<n; i++)
            nums.push_back(nums[i]);
        unordered_map<int, int>Map; // presum->idx
        Map[0]=-1;
        int sum=0, ret=INT_MAX;
        for (int i=1; i<=nums.size(); i++)
        {
            sum+=nums[i-1];
            if (Map.find(sum-x)!=Map.end()&&i>=n&&Map[sum-x]<=n&&i-Map[sum-x]<=n)
                ret=min(ret, i-Map[sum-x]);
            
            Map[sum]=i;
        }

        if (ret==INT_MAX) return -1;
        else return ret;
    }
};
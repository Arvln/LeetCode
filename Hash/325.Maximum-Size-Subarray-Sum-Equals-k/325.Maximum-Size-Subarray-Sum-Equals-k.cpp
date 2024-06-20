class Solution {
public:
    int maxSubArrayLen(vector<int> &nums, int k) {
        unordered_map<int, int>Map; // presum->idx
        Map[0]=-1;

        int sum=0, ret=0;
        for (int i=0; i<nums.size(); i++)
        {
            sum+=nums[i];

            if (Map.find(sum)==Map.end()) Map[sum]=i;
            if (Map.find(sum-k)!=Map.end()) ret=max(ret, i-Map[sum-k]);
        }
        return ret;
    }
};
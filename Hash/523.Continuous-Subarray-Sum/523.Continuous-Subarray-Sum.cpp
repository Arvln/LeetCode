class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>Map; // presum->idx
        Map[0]=-1;

        int sum=0;
        for (int i=0; i<nums.size(); i++)
        {
            sum+=nums[i];

            if (Map.find(sum%k)==Map.end()) Map[sum%k]=i;
            else if (i-Map[sum%k]>=2) return true;
        }
        return false;
    }
};
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int>Map; // {val, idx}
        for (int i=0; i<nums.size(); i++)
        {
            if (Map.find(nums[i])!=Map.end()&&i-Map[nums[i]]<=k) return true;
            Map[nums[i]]=i; 
        }
        return false;
    }
};
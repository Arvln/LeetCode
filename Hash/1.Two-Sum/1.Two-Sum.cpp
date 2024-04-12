class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>Map; // num->idx
        for (int i=0; i<nums.size(); i++)
            if (Map.find(target-nums[i])==Map.end()) Map[nums[i]]=i;
            else return {Map[target-nums[i]], i};
        return {-1, -1};
    }
};
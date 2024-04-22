class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<int>Set;
        Set.insert(nums[0]);
        for (int i=1; i<nums.size(); i++)
        {
            if (i>indexDiff) Set.erase(nums[i-indexDiff-1]);

            auto iter=Set.lower_bound(nums[i]-valueDiff);
            if (iter!=Set.end()&&abs(*iter-nums[i])<=valueDiff) return true;

            Set.insert(nums[i]);
        }
        return false;
    }
};
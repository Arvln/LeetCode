class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        multiset<int>Set;
        for (int i=0; i<nums.size(); i++)
        {
            if (i>indexDiff) Set.erase(Set.lower_bound(nums[i-indexDiff-1]));

            auto it=Set.lower_bound(nums[i]-valueDiff);
            if (it!=Set.end()&&abs(*it-nums[i])<=valueDiff) return true;

            Set.insert(nums[i]);
        }
        return false;
    }
};
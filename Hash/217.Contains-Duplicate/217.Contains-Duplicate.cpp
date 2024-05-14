class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>Set;
        for (int num : nums)
        {
            if (Set.find(num)!=Set.end()) return true;
            Set.insert(num);
        }
        return false;
    }
};
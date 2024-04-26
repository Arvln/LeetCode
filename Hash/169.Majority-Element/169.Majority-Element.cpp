class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int>Map; // num->count
        for (int num : nums)
            Map[num]++;
        for (auto &[num, count] : Map)
            if (count>nums.size()/2) return num;
        return -1;
    }
};
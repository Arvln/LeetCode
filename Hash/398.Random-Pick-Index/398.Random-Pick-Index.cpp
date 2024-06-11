class Solution {
    unordered_map<int, vector<int>>Map;
public:
    Solution(vector<int>& nums) {
        for (int i=0; i<nums.size(); i++)
            Map[nums[i]].push_back(i);
    }
    
    int pick(int target) {
        int r=rand()%Map[target].size();
        return Map[target][r];
    }
};
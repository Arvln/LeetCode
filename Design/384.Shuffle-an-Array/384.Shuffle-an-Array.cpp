class Solution {
    vector<int>origin;
public:
    Solution(vector<int>& nums) {
        origin=nums;
    }
    
    vector<int> reset() {
        return origin;
    }
    
    vector<int> shuffle() {
        vector<int>nums=origin;
        int n=nums.size();
        for (int i=0; i<n; i++)
        {
            int r=rand()%n;
            swap(nums[i], nums[r]);
        }
        return nums;
    }
};
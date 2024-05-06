class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int>Map; // sum->count
        for (int num1 : nums1)
            for (int num2 : nums2)
                Map[num1+num2]++;
        
        int ret=0;
        for (int num3 : nums3)
            for (int num4 : nums4)
                ret+=Map[-num3-num4];
        return ret;
    }
};
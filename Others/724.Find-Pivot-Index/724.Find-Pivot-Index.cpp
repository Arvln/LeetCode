class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int>pre{0};
        for (int num : nums) pre.push_back(pre.back()+num);
        
        for (int i=0; i<nums.size(); i++)
            if (pre[i]==pre.back()-pre[i+1])
                return i;
        return -1;
    }
};
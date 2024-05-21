class NumArray {
    vector<int>pre{0};
public:
    NumArray(vector<int>& nums) {
        for (int num : nums)
            pre.push_back(pre.back()+num);
    }
    
    int sumRange(int left, int right) {
        return pre[right+1]-pre[left];
    }
};
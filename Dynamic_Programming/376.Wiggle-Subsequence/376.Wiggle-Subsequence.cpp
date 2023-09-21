class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int pos=1, neg=1;
        for (int i=1; i<nums.size(); i++)
        {
            int pre_pos=pos, pre_neg=neg;
            if (nums[i]>nums[i-1])
                pos=max(pre_pos, pre_neg+1);
            else if (nums[i]<nums[i-1])
                neg=max(pre_neg, pre_pos+1);
        }
        return max(pos, neg);
    }
};
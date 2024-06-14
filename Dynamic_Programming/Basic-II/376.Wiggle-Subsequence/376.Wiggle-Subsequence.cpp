class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<int>pos(n, 1);
        vector<int>neg(n, 1);

        for (int i=0; i<n; i++)
            for (int j=0; j<i; j++)
                if (nums[i]>nums[j]) pos[i]=max(pos[i], neg[j]+1);
                else if (nums[i]<nums[j]) neg[i]=max(neg[i], pos[j]+1);
        
        int ret=1;
        for (int i=0; i<n; i++)
            ret=max({ret, pos[i], neg[i]});
        return ret;
    }
};
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ret=0;
        for (int i=0; i<32; i++)
        {
            int s1=0, s2=0;
            for (int k=1; k<nums.size(); k++)
                s1+=(k>>i)&1;
            for (int num : nums)
                s2+=(num>>i)&1;
            
            if (s2>s1) ret+=(1<<i);
        }
        return ret;
    }
};
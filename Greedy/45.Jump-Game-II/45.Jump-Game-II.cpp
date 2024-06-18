class Solution {
public:
    int jump(vector<int>& nums) {
        int reach=0, next=0, ret=0;
        for (int i=0; i<=reach; i++)
        {
            if (reach>=nums.size()-1) return ret;

            next=max(next, i+nums[i]);
            if (i==reach)
            {
                reach=next;
                ret++;
            }
        }
        return -1;
    }
};
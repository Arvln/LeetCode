class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach=0, next=0;
        for (int i=0; i<=reach; i++)
        {
            if (next>=nums.size()-1) return true;

            next=max(next, i+nums[i]);
            if (i==reach)
            {
                if (next==reach) break;
                reach=next;
            }
        }
        return false;
    }
};
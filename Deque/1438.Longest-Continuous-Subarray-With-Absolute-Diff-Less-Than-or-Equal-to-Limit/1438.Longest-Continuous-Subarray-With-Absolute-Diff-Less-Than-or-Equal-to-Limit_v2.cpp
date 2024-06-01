class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int>maxdq, mindq;
        int l=0, r=0, ret=0;
        while (r<nums.size())
        {
            while (!maxdq.empty()&&nums[maxdq.back()]<=nums[r])
                maxdq.pop_back();
            while (!mindq.empty()&&nums[mindq.back()]>=nums[r])
                mindq.pop_back();
            maxdq.push_back(r);
            mindq.push_back(r);
            r++;

            while (!maxdq.empty()&&!mindq.empty()&&nums[maxdq.front()]-nums[mindq.front()]>limit)
            {
                if (l==maxdq.front()) maxdq.pop_front();
                if (l==mindq.front()) mindq.pop_front();
                l++;
            }
            ret=max(ret, r-l);
        }
        return ret;
    }
};
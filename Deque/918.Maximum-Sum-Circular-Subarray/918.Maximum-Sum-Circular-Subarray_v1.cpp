class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        for (int i=0; i<n; i++)
            nums.push_back(nums[i]);
        vector<int>pre{0};
        for (int num : nums)
            pre.push_back(pre.back()+num);
        
        deque<int>dq{0};
        int ret=INT_MIN;
        for (int i=1; i<=nums.size(); i++)
        {
            while (!dq.empty()&&i-dq.front()>n)
                dq.pop_front();
            ret=max(ret, pre[i]-pre[dq.front()]);
            while (!dq.empty()&&pre[dq.back()]>=pre[i])
                dq.pop_back();
            dq.push_back(i);
        }
        return ret;
    }
};
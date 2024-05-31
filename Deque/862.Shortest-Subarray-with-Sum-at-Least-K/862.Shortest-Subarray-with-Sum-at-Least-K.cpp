class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        vector<long>pre{0};
        for (int num : nums)
            pre.push_back(pre.back()+num);
        
        int ret=INT_MAX;
        deque<int>dq{0};
        for (int i=1; i<=nums.size(); i++)
        {
            while (!dq.empty()&&pre[i]-pre[dq.front()]>=k)
            {
                ret=min(ret, i-dq.front());
                dq.pop_front();
            }
            while (!dq.empty()&&pre[dq.back()]>=pre[i])
                dq.pop_back();
            dq.push_back(i);
        }
        if (ret==INT_MAX) return -1;
        else return ret;
    }
};
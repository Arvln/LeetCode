class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        vector<int>pre{0};
        for (int num : nums)
            pre.push_back(pre.back()+num);
        
        deque<int>dq{0};
        int ret=INT_MAX;
        for (int i=1; i<=n; i++)
        {
            while (!dq.empty()&&pre[i]-pre[dq.front()]>=target)
            {
                ret=min(ret, i-dq.front());
                dq.pop_front();
            }
            
            while (!dq.empty()&&pre[dq.back()]>=pre[i])
                dq.pop_back();
            dq.push_back(i);
        }
        
        if (ret==INT_MAX) return 0;
        else return ret;
    }
};
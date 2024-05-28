class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {        
        int n=nums.size();
        vector<int>pre{0};
        for (int num : nums)
            pre.push_back(pre.back()+num);
        
        unordered_map<int, int>Map; // presum->count
        Map[0]=1;
        
        int ret=0;
        for (int i=1; i<=n; i++)
        {
            ret+=Map[pre[i]-k];
            Map[pre[i]]++;
        }
        return ret;
    }
};
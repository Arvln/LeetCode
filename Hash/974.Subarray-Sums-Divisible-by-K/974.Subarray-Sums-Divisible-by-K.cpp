class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int>Map; // presum->count
        Map[0]=1;
        int sum=0, ret=0;
        for (int num : nums)
        {
            sum+=num;
            int r=(sum%k+k)%k;
            if (Map.find(r)!=Map.end()) ret+=Map[r];
            Map[r]++;
        }
        return ret;
    }
};
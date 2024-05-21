class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int>Map; // presum->idx
        Map[0]=-1;
        
        int sum=0, ret=0;
        for (int i=0; i<nums.size(); i++)
        {
            if (nums[i]==1) sum++;
            else sum--;

            if (Map.find(sum)==Map.end()) Map[sum]=i;
            else ret=max(ret, i-Map[sum]);
        }
        return ret;
    }
};
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int diff=0, n=nums.size();
        for (int i=0; i<n; i++)
        {
            nums.push_back(i+1);
            diff^=(i+1)^nums[i];
        }
        diff=diff&(-diff);
        vector<int>ret(2, 0);
        for (int i=0; i<nums.size(); i++)
            if ((nums[i]&diff)==0) ret[0]^=nums[i];
            else ret[1]^=nums[i];
        for (int i=0; i<n; i++)
            if (nums[i]==ret[1]) swap(ret[0], ret[1]);
        return ret;
    }
};
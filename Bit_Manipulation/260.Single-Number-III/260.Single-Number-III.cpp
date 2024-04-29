class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long diff=0;
        for (int num : nums)
            diff^=num;
        diff=diff&(-diff);
        vector<int>ret(2, 0);
        for (int num : nums)
            if ((num&diff)==0) ret[0]^=num;
            else ret[1]^=num;
        return ret;
    }
};
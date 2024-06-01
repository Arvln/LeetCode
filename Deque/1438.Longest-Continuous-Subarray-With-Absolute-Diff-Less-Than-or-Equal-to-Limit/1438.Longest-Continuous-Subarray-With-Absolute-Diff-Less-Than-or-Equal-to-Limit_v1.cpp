class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int>Set;
        int l=0, r=0, ret=0;
        while (r<nums.size())
        {
            Set.insert(nums[r]);
            r++;

            while (*Set.rbegin()-*Set.begin()>limit)
            {
                Set.erase(Set.lower_bound(nums[l]));
                l++;
            }
            ret=max(ret, r-l);
        }
        return ret;
    }
};
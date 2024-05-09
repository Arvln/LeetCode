class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>Set;
        for (int num : nums1)
            Set.insert(num);
        
        vector<int>ret;
        for (int num : nums2)
            if (Set.find(num)!=Set.end())
            {
                Set.erase(num);
                ret.push_back(num);
            }
        return ret;
    }
};
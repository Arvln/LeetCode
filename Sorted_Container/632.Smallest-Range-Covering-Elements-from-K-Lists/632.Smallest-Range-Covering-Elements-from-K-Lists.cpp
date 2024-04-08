class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        set<pair<int, int>>Set;
        vector<int>pointers;
        for (int i=0; i<nums.size(); i++)
        {
            Set.insert({nums[i][0], i});
            pointers.push_back(0);
        }

        int range=INT_MAX;
        vector<int>ret;
        while (!Set.empty())
        {
            if (Set.rbegin()->first-Set.begin()->first<range)
            {
                range=Set.rbegin()->first-Set.begin()->first;
                ret={Set.begin()->first, Set.rbegin()->first};
            }
            int i=Set.begin()->second;
            pointers[i]++;
            if (pointers[i]==nums[i].size()) break;
            Set.erase(Set.begin());
            Set.insert({nums[i][pointers[i]], i});
        }
        return ret;
    }
};
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int>Map; // type->count
        int l=0, r=0, ret=0;
        while (r<fruits.size())
        {
            Map[fruits[r]]++;
            r++;

            while (Map.size()>2)
            {
                Map[fruits[l]]--;
                if (Map[fruits[l]]==0) Map.erase(fruits[l]);
                l++;
            }
            ret=max(ret, r-l);
        }
        return ret;
    }
};
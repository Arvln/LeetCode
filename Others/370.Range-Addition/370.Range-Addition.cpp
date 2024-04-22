class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>> &updates) {
        vector<int>diff(length+1, 0);
        for (auto &update : updates)
        {
            int start=update[0], end=update[1], increment=update[2];
            diff[start]+=increment;
            diff[end+1]-=increment;
        }

        int sum=0;
        vector<int>ret;
        for (int i=0; i<length; i++)
        {
            sum+=diff[i];
            ret.push_back(sum);
        }
        return ret;
    }
};
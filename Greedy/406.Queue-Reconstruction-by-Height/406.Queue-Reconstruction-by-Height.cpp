class Solution {
    static bool cmp(vector<int>&a, vector<int>&b)
    {
        if (a[0]==b[0]) return a[1]<b[1];
        else return a[0]>b[0];
    }
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>>ret;
        for (auto &person : people)
        {
            int pos=person[1];
            ret.insert(ret.begin()+pos, person);
        }
        return ret;
    }
};
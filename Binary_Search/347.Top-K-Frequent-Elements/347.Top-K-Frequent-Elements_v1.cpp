class Solution {
    unordered_map<int, int>Map; // num->freq
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        for (int num : nums)
            Map[num]++;

        int l=1, r=nums.size();
        while (l<=r)
        {
            int mid=l+(r-l)/2;

            if (count(nums, mid)<k) r=mid-1;
            else l=mid+1;
        }

        vector<int>ret;
        for (auto &[num, freq] : Map)
            if (freq>=r) ret.push_back(num);
        return ret;
    }
    int count(vector<int> &nums, int t)
    {
        int ret=0;
        for (auto &[num, freq] : Map)
            if (freq>=t) ret++;
        return ret;
    }
};
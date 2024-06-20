class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        priority_queue<pair<int, int>>pq;
        for (int i=0; i<n; i++)
            pq.push({nums2[i], i});
        
        sort(nums1.begin(), nums1.end());
        int l=0, r=n-1;
        vector<int>ret(n);
        while (!pq.empty())
        {
            auto [maxVal, i]=pq.top();
            pq.pop();

            if (maxVal<nums1[r])
            {
                ret[i]=nums1[r];
                r--;
            }
            else
            {
                ret[i]=nums1[l];
                l++;
            }
        }
        return ret;
    }
};
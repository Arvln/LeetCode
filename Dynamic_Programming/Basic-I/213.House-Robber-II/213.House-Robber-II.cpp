class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if (n==1) return nums[0];
        nums.insert(nums.begin(), 0);
        vector<int>rob1(n+1, 0);
        vector<int>norob1(n+1, 0);
        for (int i=2; i<=n; i++)
        {
            rob1[i]=norob1[i-1]+nums[i];
            norob1[i]=max(rob1[i-1], norob1[i-1]);
        }

        vector<int>rob2(n, 0);
        vector<int>norob2(n, 0);
        for (int i=1; i<n; i++)
        {
            rob2[i]=norob2[i-1]+nums[i];
            norob2[i]=max(rob2[i-1], norob2[i-1]);
        }
        return max({rob1[n], norob1[n], rob2[n-1], norob2[n-1]});
    }
};
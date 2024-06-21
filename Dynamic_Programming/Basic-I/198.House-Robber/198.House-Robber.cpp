class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(), 0);
        vector<int>rob(n+1, 0);
        vector<int>norob(n+1, 0);

        for (int i=1; i<=n; i++)
        {
            rob[i]=norob[i-1]+nums[i];
            norob[i]=max(rob[i-1], norob[i-1]);
        }
        return max(rob[n], norob[n]);
    }
};
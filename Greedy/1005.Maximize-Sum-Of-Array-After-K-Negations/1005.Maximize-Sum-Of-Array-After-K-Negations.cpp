class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int sum=0, minVal=100;
        for (int num : nums)
        {
            if (num<0&&k>0)
            {
                k--;
                num*=-1;
            }
            minVal=min(minVal, num);
            sum+=num;
        }

        if (k%2==0) return sum;
        else return sum-2*minVal;
    }
};
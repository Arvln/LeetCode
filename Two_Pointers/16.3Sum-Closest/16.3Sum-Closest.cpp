class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int diff=INT_MAX, ret;
        int last=-1001;
        for (int k=0; k<nums.size(); k++)
        {
            if (last==nums[k]) continue;
            last=nums[k];

            target-=nums[k];
            int i=k+1, j=nums.size()-1;
            while (i<j)
            {
                int sum=nums[i]+nums[j];
                if (abs(target-sum)<diff)
                {
                    diff=abs(target-sum);
                    ret=nums[k]+sum;
                }

                if (sum==target) return ret;
                else if (sum<target) i++;
                else j--;
            }
            target+=nums[k];
        }
        return ret;
    }
};
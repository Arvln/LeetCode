class Solution {
    int sorted[50005];
    int temp[50005];
    int ret=0;
public:
    int reversePairs(vector<int>& nums) {
        for (int i=0; i<nums.size(); i++)
            sorted[i]=nums[i];
        dfs(nums, 0, nums.size()-1);
        return ret;
    }
    void dfs(vector<int> &nums, int l, int r)
    {
        if (l==r) return;

        int mid=l+(r-l)/2;
        dfs(nums, l, mid);
        dfs(nums, mid+1, r);

        for (int i=mid+1; i<=r; i++)
        {
            auto iter=upper_bound(sorted+l, sorted+mid+1, (long)2*nums[i]);
            ret+=(sorted+mid+1)-iter;
        }

        merge(l, mid, r);
    }
    void merge(int l, int mid, int r)
    {
        for (int i=l; i<=r; i++)
            temp[i]=sorted[i];

        for (int i=l, j=mid+1, k=l; k<=r; k++)
        {
            if (i==mid+1)
            {
                sorted[k]=temp[j];
                j++;
            }
            else if (j==r+1)
            {
                sorted[k]=temp[i];
                i++;
            }
            else if (temp[i]<temp[j])
            {
                sorted[k]=temp[i];
                i++;
            }
            else
            {
                sorted[k]=temp[j];
                j++;
            }
        }
    }
};
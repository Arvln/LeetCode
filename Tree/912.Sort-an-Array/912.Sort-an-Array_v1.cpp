class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        dfs(nums, 0, nums.size()-1);
        return nums;
    }
    void dfs(vector<int>&nums, int l, int r)
    {
        if (l>=r) return;

        int mid=locate(nums, l, r);
        dfs(nums, l, mid-1);
        dfs(nums, mid+1, r);
    }
    int locate(vector<int>&nums, int l, int r)
    {
        int idx=rand()%(r-l+1)+l;
        int pivot=nums[idx];
        swap(nums[l], nums[idx]);

        int i=l+1, j=r;
        while (i<=j)
        {
            while (i<r&&nums[i]<=pivot) i++;
            while (j>l&&nums[j]>pivot) j--;

            if (i>=j) break;
            swap(nums[i], nums[j]);
        }
        swap(nums[l], nums[j]);
        return j;
    }
};
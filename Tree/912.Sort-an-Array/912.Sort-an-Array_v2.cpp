class Solution {
    vector<int>temp;
public:
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        temp.resize(n);
        dfs(nums, 0, n-1);
        return nums;
    }
    void dfs(vector<int>&nums, int l, int r)
    {
        if (l==r) return;
   
        int mid=l+(r-l)/2;
        dfs(nums, l, mid);
        dfs(nums, mid+1, r);

        merge(nums, l, mid, r);
    }
    void merge(vector<int>&nums, int l, int mid, int r)
    {
        for (int i=l; i<=r; i++)
            temp[i]=nums[i];
        
        int i=l, j=mid+1;
        for (int k=l; k<=r; k++)
        {
            if (i==mid+1)
            {
                nums[k]=temp[j];
                j++;
            }
            else if (j==r+1)
            {
                nums[k]=temp[i];
                i++;
            }
            else if (temp[i]<temp[j])
            {
                nums[k]=temp[i];
                i++;
            }
            else
            {
                nums[k]=temp[j];
                j++;
            }
        }
    }
};
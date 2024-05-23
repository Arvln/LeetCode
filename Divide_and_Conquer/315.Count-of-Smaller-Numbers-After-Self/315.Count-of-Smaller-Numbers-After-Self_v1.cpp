class Solution {
    vector<int>nums, sorted, temp, smaller;
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        this->nums=nums;
        sorted=nums;
        temp.resize(n);
        smaller.resize(n);
        dfs(0, n-1);
        return smaller;
    }
    void dfs(int l, int r)
    {
        if (l==r) return;

        int mid=l+(r-l)/2;
        dfs(l, mid);
        dfs(mid+1, r);

        for (int i=l; i<=mid; i++)
        {
            auto iter=lower_bound(sorted.begin()+mid+1, sorted.begin()+r+1, nums[i]);
            smaller[i]+=iter-(sorted.begin()+mid+1);
        }
        
        merge(l, mid, r);
    }
    void merge(int l, int mid, int r)
    {
        for (int i=l; i<=r; i++)
            temp[i]=sorted[i];
        for (int i=l, j=mid+1, k=l; k<=r; k++)
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
};
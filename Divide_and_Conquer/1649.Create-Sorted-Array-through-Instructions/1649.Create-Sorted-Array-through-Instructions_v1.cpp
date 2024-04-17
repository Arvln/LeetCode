class Solution {
    long sorted[100005];
    long temp[100005];
    long smaller[100005];
    long count[100005];
    int M=1e9+7;
public:
    int createSortedArray(vector<int>& instructions) {
        int n=instructions.size();
        for (int i=0; i<n; i++)
            sorted[i]=instructions[i];
        dfs(instructions, 0, n-1);
        long ret=0;
        for (int i=0; i<n; i++)
        {
            ret+=min(smaller[i], i-smaller[i]-count[instructions[i]]);
            count[instructions[i]]++;
        }
        return ret%M;
    }
    void dfs(vector<int>&nums, int l, int r)
    {
        if (l==r) return;

        int mid=l+(r-l)/2;
        dfs(nums, l, mid);
        dfs(nums, mid+1, r);

        for (int i=mid+1; i<=r; i++)
        {
            auto iter=lower_bound(sorted+l, sorted+mid+1, nums[i]);
            smaller[i]+=iter-(sorted+l);
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
class Solution {
    int n;
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        n=matrix.size();
        int l=matrix[0][0], r=matrix[n-1][n-1];
        while (l<=r)
        {
            int mid=l+(r-l)/2;

            if (count(matrix, mid)<k) l=mid+1;
            else r=mid-1;
        }
        return l;
    }
    int count(vector<vector<int>>&grid, int t)
    {
        int i=0, j=n-1, ret=0;
        while (i<n&&j>=0)
        {
            if (grid[i][j]<=t)
            {
                ret+=j+1;
                i++;
            }
            else j--;
        }
        return ret;
    }
};
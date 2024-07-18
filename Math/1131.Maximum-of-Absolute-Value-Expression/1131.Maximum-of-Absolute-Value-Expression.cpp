class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        int d[n][3];
        for (int i=0; i<n; i++)
        {
            d[i][0]=arr1[i];
            d[i][1]=arr2[i];
            d[i][2]=i;
        }

        int ret=0;
        for (int sign=0; sign<(1<<3); sign++)
        {
            int minVal=INT_MAX, maxVal=INT_MIN;
            for (int i=0; i<n; i++)
            {
                int sum=0;
                for (int j=0; j<3; j++)
                    if ((sign>>j)&1==1) sum+=d[i][j];
                    else sum+=-d[i][j];
                
                minVal=min(minVal, sum);
                maxVal=max(maxVal, sum);
            }
            ret=max(ret, maxVal-minVal);
        }
        return ret;
    }
};
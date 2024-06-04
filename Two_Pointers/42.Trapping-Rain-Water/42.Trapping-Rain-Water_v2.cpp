class Solution {
public:
    int trap(vector<int>& height) {
        int lmax=0, rmax=0, ret=0;
        int i=0, j=height.size()-1;
        while (i<j)
        {
            lmax=max(lmax, height[i]);
            rmax=max(rmax, height[j]);

            if (lmax<rmax)
            {
                ret+=lmax-height[i];
                i++;
            }
            else
            {
                ret+=rmax-height[j];
                j--;
            }
        }
        return ret;
    }
};
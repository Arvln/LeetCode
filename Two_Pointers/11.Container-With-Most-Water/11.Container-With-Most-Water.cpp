class Solution {
public:
    int maxArea(vector<int>& height) {
        int ret=0;
        int i=0, j=height.size()-1;
        while (i<j)
        {
            ret=max(ret, min(height[i], height[j])*(j-i));

            if (height[i]>height[j]) j--;
            else i++;
        }
        return ret;
    }
};
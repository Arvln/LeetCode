class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int>ret(n);
        for (int i=0, j=n-1, k=j; k>=0; k--)
        {
            int x=nums[i]*nums[i], y=nums[j]*nums[j];

            if (x<y)
            {
                ret[k]=y;
                j--;
            }
            else
            {
                ret[k]=x;
                i++;
            }
        }
        return ret;
    }
};
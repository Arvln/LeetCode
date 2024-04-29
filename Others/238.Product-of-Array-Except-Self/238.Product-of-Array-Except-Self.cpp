class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>front(n);
        vector<int>back(n);
        int prod1=1, prod2=1;
        for (int i=0; i<n; i++)
        {
            prod1*=nums[i];
            prod2*=nums[n-1-i];
            front[i]=prod1;
            back[n-1-i]=prod2;
        }
        vector<int>ret(n);
        for (int i=0; i<n; i++)
            if (i==0) ret[0]=back[i+1];
            else if (i==n-1) ret[n-1]=front[i-1];
            else ret[i]=front[i-1]*back[i+1];
        return ret;
    }
};
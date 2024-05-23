class Solution {
    class BIT {
        int n;
        vector<long long>arr;
    public:
        void init(int n)
        {
            this->n=n;
            arr.resize(n+1);
        }
        void updateDelta(int i, long long delta)
        {
            i++;
            while (i<=n)
            {
                arr[i]+=delta;
                i+=i&-i;
            }
        }
        long long queryPresum(int i)
        {
            i++;
            long long result=0;
            while (i>0)
            {
                result+=arr[i];
                i-=i&-i;
            }
            return result;
        }
        long long sumRange(int i, int j)
        {
            return queryPresum(j)-queryPresum(i-1);
        }
    };
    int maxN=20001;
public:
    vector<int> countSmaller(vector<int>& nums) {
        BIT bit;
        bit.init(maxN);
        int n=nums.size();
        vector<int>ret(n);
        for (int i=n-1; i>=0; i--)
        {
            int num=nums[i]+10001;
            ret[i]=bit.sumRange(1, num-1);
            bit.updateDelta(num, 1);
        }
        return ret;
    }
};
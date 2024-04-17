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
            while (i<=n)
            {
                arr[i]+=delta;
                i+=i&-i;
            }
        }
        long long queryPresum(int i)
        {
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
    int M=1e9+7;
public:
    int createSortedArray(vector<int>& instructions) {
        BIT bit;
        bit.init(1e5);
        long long ret=0;
        for (int i=0; i<instructions.size(); i++)
        {
            int num=instructions[i];
            bit.updateDelta(num, 1);
            ret+=min(bit.sumRange(1, num-1), bit.sumRange(num+1, 1e5));
        }
        return ret%M;
    }
};
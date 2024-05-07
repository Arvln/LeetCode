class NumArray {
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
        long long queryPreSum(int i)
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
            return queryPreSum(j)-queryPreSum(i-1);
        }
    };
    BIT bit;
    vector<int>nums;
public:
    NumArray(vector<int>& nums) {
        this->nums=nums;
        int n=nums.size();
        bit.init(n);
        for (int i=0; i<n; i++)
            bit.updateDelta(i+1, nums[i]);
    }
    
    void update(int index, int val) {
        bit.updateDelta(index+1, val-nums[index]);
        nums[index]=val;
    }
    
    int sumRange(int left, int right) {
        return bit.sumRange(left+1, right+1);
    }
};
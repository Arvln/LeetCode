class Solution {
    class BIT {
        int n;
        vector<int>arr;
    public:
        void init(int n)
        {
            this->n=n;
            arr.resize(n+1);
        }
        void updateDelta(int i, int delta)
        {
            while (i<=n)
            {
                arr[i]+=delta;
                i+=i&-i;
            }
        }
        int queryPresum(int i)
        {
            int result=0;
            while (i>0)
            {
                result+=arr[i];
                i-=i&-i;
            }
            return result;
        }
        int sumRange(int j, int i)
        {
            return queryPresum(i)-queryPresum(j-1);
        }
    };
    int M=1e9+7;
public:
    int subarraysWithMoreZerosThanOnes(vector<int> &nums) {
        int sum=0;
        set<int>Set;
        Set.insert(0);
        for (int num : nums)
        {
            if (num==1) sum++;
            else sum--;
            Set.insert(sum);
        }
        unordered_map<int, int>Map; // sum->idx
        int i=1;
        for (int sum : Set)
        {
            Map[sum]=i;
            i++;
        }
        BIT bit;
        bit.init(Map.size());

        sum=0;
        bit.updateDelta(Map[0], 1);
        int ret=0;
        for (int num : nums)
        {
            if (num==1) sum++;
            else sum--;

            ret+=bit.sumRange(1, Map[sum]-1);
            ret%=M;
            bit.updateDelta(Map[sum], 1);
        }
        return ret;
    }
};
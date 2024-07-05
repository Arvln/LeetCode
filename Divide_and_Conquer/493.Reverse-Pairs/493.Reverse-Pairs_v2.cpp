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
public:
    int reversePairs(vector<int>& nums) {
        set<long>Set;
        for (long num : nums)
        {
            Set.insert(num);
            Set.insert(num*2);
        }
        unordered_map<long, int>Map; // num->idx
        int i=1;
        for (long num : Set)
        {
            Map[num]=i;
            i++;
        }
        BIT bit;
        bit.init(Map.size());

        int ret=0;
        for (long num : nums)
        {
            ret+=bit.sumRange(Map[num*2]+1, Map.size());
            bit.updateDelta(Map[num], 1);
        }
        return ret;
    }
};
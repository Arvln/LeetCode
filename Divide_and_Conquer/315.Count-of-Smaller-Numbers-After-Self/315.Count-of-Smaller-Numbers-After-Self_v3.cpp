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
    vector<int> countSmaller(vector<int>& nums) {
        set<int>Set;
        for (int num : nums)
            Set.insert(num);
        unordered_map<int, int>Map; // num->idx
        int i=1;
        for (int num : Set)
        {
            Map[num]=i;
            i++;
        }
        int n=nums.size();

        BIT bit;
        bit.init(n);
        vector<int>counts(n);
        for (int i=n-1; i>=0; i--)
        {
            counts[i]=bit.sumRange(1, Map[nums[i]]-1);
            bit.updateDelta(Map[nums[i]], 1);
        }
        return counts;
    }
};
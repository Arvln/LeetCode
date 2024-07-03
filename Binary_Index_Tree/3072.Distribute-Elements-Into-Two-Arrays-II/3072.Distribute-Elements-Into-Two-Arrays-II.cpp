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
        int sumRange(int i, int j)
        {
            return queryPresum(j)-queryPresum(i-1);
        }
    };
public:
    vector<int> resultArray(vector<int>& nums) {
        set<int>Set(nums.begin(), nums.end());
        unordered_map<int, int>Map; // num->idx
        int i=1;
        for (int num : Set)
        {
            Map[num]=i;
            i++;
        }
        BIT bit1, bit2;
        bit1.init(Map.size());
        bit2.init(Map.size());

        vector<int>arr1, arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        bit1.updateDelta(Map[nums[0]], 1);
        bit2.updateDelta(Map[nums[1]], 1);

        for (int i=2; i<nums.size(); i++)
        {
            int sum1=bit1.sumRange(Map[nums[i]]+1, Map.size());
            int sum2=bit2.sumRange(Map[nums[i]]+1, Map.size());

            if (sum1>sum2)
            {
                arr1.push_back(nums[i]);
                bit1.updateDelta(Map[nums[i]], 1);
            }
            else if (sum1<sum2)
            {
                arr2.push_back(nums[i]);
                bit2.updateDelta(Map[nums[i]], 1);
            }
            else if (arr1.size()>arr2.size())
            {
                arr2.push_back(nums[i]);
                bit2.updateDelta(Map[nums[i]], 1);
            }
            else
            {
                arr1.push_back(nums[i]);
                bit1.updateDelta(Map[nums[i]], 1);
            }
        }

        for (int num : arr2)
            arr1.push_back(num);
        return arr1;
    }
};
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left=0, right=0, ret=0, k=2, n=fruits.size();
        vector<int> records(n, 0);
        while (right<n)
        {
            if (records[fruits[right]]==0) k-=1;
            records[fruits[right]]+=1;
            right++;

            while (left<right&&k<0)
            {
                if (records[fruits[left]]==1) k+=1;
                records[fruits[left]]-=1;
                left++;
            }
            ret=max(ret, right-left);
        }
        return ret;
    }
};
class Solution {
public:
    int nthUglyNumber(int n) {
        int i=0, j=0, k=0;
        vector<int> ret{1};
        for (int p=0; p<n-1; p++)
        {
            int cur=min({ret[i]*2, ret[j]*3, ret[k]*5});
            ret.push_back(cur);

            if (cur==ret[i]*2) i++;
            if (cur==ret[j]*3) j++;
            if (cur==ret[k]*5) k++;
        }
        return ret.back();
    }
};
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ret(n+1, 0);
        for (int i=0; i<=n; i++)
        {
            int j=i;
            while (j>0)
            {
                if (j&1==1) ret[i]++;
                j>>=1;
            }
        }
        return ret;
    }
};
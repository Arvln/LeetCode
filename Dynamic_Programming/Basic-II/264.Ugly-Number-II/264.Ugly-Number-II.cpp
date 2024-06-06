class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>ugly{1};
        int i=0, j=0, k=0;
        while (ugly.size()<n)
        {
            int next=min({ugly[i]*2, ugly[j]*3, ugly[k]*5});
            ugly.push_back(next);

            if (ugly[i]*2==next) i++;
            if (ugly[j]*3==next) j++;
            if (ugly[k]*5==next) k++;
        }
        return ugly.back();
    }
};
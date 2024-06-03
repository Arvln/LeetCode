class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int N=primes.size();
        vector<long>ugly{1};
        vector<int>pointers(N, 0);
        while (ugly.size()<n)
        {
            long next=primes[0]*ugly[pointers[0]];
            for (int i=1; i<N; i++)
                next=min(next, primes[i]*ugly[pointers[i]]);
            ugly.push_back(next);
            for (int i=0; i<N; i++)
                if (primes[i]*ugly[pointers[i]]==next) pointers[i]++;
        }
        return ugly.back();
    }
};
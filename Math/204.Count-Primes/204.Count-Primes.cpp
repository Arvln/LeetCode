class Solution {
public:
    int countPrimes(int n) {
        vector<int>primes(n+1, 1);
        for (int i=2; i<=n/i; i++)
            for (int j=2; j<=n/i; j++)
                primes[i*j]=0;
        
        int ret=0;
        for (int i=2; i<n; i++)
            ret+=primes[i];
        return ret;
    }
};
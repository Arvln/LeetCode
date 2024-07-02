class Solution {
    vector<int>primes{2,3,5,7,11,13,17,19,23,29};
    int M=1e9+7;
public:
    int numberOfGoodSubsets(vector<int>& nums) {
        int n=primes.size();
        unordered_map<int, int>Map; // num->count
        for (int num : nums)
            Map[num]++;
        
        vector<long>dp(1<<n, 0);
        dp[0]=1;
        for (auto &[num, count] : Map)
        {
            if (num==1) continue;
            int mask=encode(num);
            if (mask==-1) continue;

            auto pre_dp=dp;
            for (int state=1; state<(1<<n); state++)
            {
                if ((state&mask)==mask)
                {
                    dp[state]+=pre_dp[state-mask]*count%M;
                    dp[state]%=M;
                }
            }
        }

        long ret=0;
        for (int state=1; state<(1<<n); state++)
            ret=(ret+dp[state])%M;
        for (int i=0; i<Map[1]; i++)
            ret=(ret*2)%M;
        return ret;
    }
    int encode(int num)
    {
        int ret=0;
        for (int i=0; i<primes.size(); i++)
        {
            if (num%primes[i]==0)
            {
                ret+=1<<i;
                num/=primes[i];
            }
            if (num%primes[i]==0) return -1;
        }
        return ret;
    }
};
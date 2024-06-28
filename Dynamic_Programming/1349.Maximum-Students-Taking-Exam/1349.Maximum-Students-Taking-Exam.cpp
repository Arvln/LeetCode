class Solution {
    vector<vector<char>>seats;
    int m, n;
public:
    int maxStudents(vector<vector<char>>& seats) {
        m=seats.size(), n=seats[0].size();
        int N=1<<n;
        this->seats=seats;
        vector<int>dp(N, 0);
        for (int p=0; p<N; p++)
            if (rowValid(p, 0)) dp[p]=count(p, 0);

        for (int row=1; row<m; row++)
        {
            auto pre_dp=dp;
            for (int cur=0; cur<N; cur++)
            {
                if (rowValid(cur, row)==false) continue;
                dp[cur]=0;
                for (int pre=0; pre<N; pre++)
                {
                    if (rowValid(pre, row-1)==false) continue;
                    if (crossValid(pre, cur, row)==false) continue;

                    dp[cur]=max(dp[cur], pre_dp[pre]+count(cur, row));
                }
            }
        }

        int ret=0;
        for (int p=0; p<N; p++)
            if (rowValid(p, m-1)) ret=max(ret, dp[p]);
        return ret;
    }
    int count(int p, int row)
    {
        int ret=0;
        for (int i=0; i<n; i++)
            ret+=(p>>i)&1;
        return ret;
    }
    bool crossValid(int pre, int cur, int row)
    {
        vector<int>temp1, temp2;
        for (int i=0; i<n; i++)
        {
            temp1.push_back(cur%2);
            temp2.push_back(pre%2);
            cur/=2;
            pre/=2;
        }
        for (int i=0; i<n; i++)
        {
            if (i>0&&temp1[i]==1&&temp2[i-1]==1) return false;
            if (i<n-1&&temp1[i]==1&&temp2[i+1]==1) return false;
        }
        return true;
    }
    bool rowValid(int p, int row)
    {
        vector<int>temp;
        for (int i=0; i<n; i++)
        {
            temp.push_back(p%2);
            p/=2;
        }
        for (int i=0; i<n; i++)
        {
            if (i>0&&temp[i]==1&&temp[i-1]==1) return false;
            if (temp[i]==1&&seats[row][i]=='#') return false;
        }
        return true;
    }
};
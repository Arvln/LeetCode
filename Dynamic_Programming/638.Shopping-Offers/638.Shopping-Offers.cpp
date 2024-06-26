class Solution {
    vector<pair<int, int>>offers;
    int n;
    int memo[1<<24];
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        n=price.size();
        for (auto &offer : special)
        {
            int total=0, status=0;
            for (int i=0; i<n; i++)
            {
                total+=price[i]*offer[i];
                status+=offer[i]<<(4*i);
            }
            if (offer[n]<total) offers.push_back({status, offer[n]});
        }
        for (int i=0; i<n; i++)
            offers.push_back({1<<(4*i), price[i]});

        int target=0;
        for (int i=0; i<n; i++)
            target+=needs[i]<<(4*i);
        return dfs(target);
    }
    int dfs(int status)
    {
        if (status==0) return 0;
        else if (memo[status]!=0) return memo[status];
        
        int ret=INT_MAX;
        for (auto &[amount, price] : offers)
        {
            int next=0;
            int flag=1;
            for (int i=0; i<n; i++)
            {
                int need=(status>>(4*i))&15, count=(amount>>(4*i))&15;

                if (need<count)
                {
                    flag=0;
                    break;
                }
                else next+=(need-count)<<(4*i);
            }

            if (flag==1) ret=min(ret, price+dfs(next));
        }
        memo[status]=ret;
        return ret;
    }
};
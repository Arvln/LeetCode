class Solution {
    unordered_map<int, int>keyToVal;
    unordered_map<int, vector<int>>nexts;
    int ret=0;
public:
    int pathSum(vector<int> &nums) {
        for (int num : nums)
        {
            int key=num/10, val=num%10;
            keyToVal[key]=val;

            int x=key/10, y=key%10;
            x-=1;
            y=y/2+y%2;
            nexts[x*10+y].push_back(key);
        }

        dfs(11, keyToVal[11]);
        return ret;
    }
    void dfs(int node, int sum)
    {
        if (nexts[node].empty()) ret+=sum;

        for (int next : nexts[node])
            dfs(next, sum+keyToVal[next]);
    }
};
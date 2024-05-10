using AI3=array<int, 3>;
class Solution {
    vector<int>parents;
    int count;
public:
    int minimumCost(int n, vector<vector<int>> &connections) {
        parents.resize(n+1);
        for (int i=1; i<=n; i++)
            parents[i]=i;
        count=n;
        priority_queue<AI3, vector<AI3>, greater<>>pq; // {cost, x, y}
        for (auto &connection : connections)
        {
            int x=connection[0], y=connection[1], cost=connection[2];
            pq.push({cost, x, y});
        }
        int ret=0;
        while (!pq.empty()&&count>1)
        {
            AI3 connection=pq.top();
            pq.pop();
            int cost=connection[0], x=connection[1], y=connection[2];

            if (find(x)!=find(y))
            {
                Union(x, y);
                ret+=cost;
            }
        }

        if (count==1) return ret;
        else return -1;
    }
    int find(int p)
    {
        if (p!=parents[p]) parents[p]=find(parents[p]);
        return parents[p];
    }
    void Union(int p, int q)
    {
        int rootP=find(p);
        int rootQ=find(q);

        if (rootP==rootQ) return;
        parents[rootP]=rootQ;
        count--;
    }
};
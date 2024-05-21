using AI3=array<int, 3>;
class Solution {
    vector<int>parents;
    int count;
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        for (int i=0; i<n; i++)
            parents.push_back(i);
        count=n;

        priority_queue<AI3, vector<AI3>, greater<>>pq; // {cost, start, end}
        for (int i=0; i<n; i++)
            for (int j=i+1; j<n; j++)
                pq.push({abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]), i, j});

        int ret=0;
        while (!pq.empty()&&count>1)
        {
            AI3 cur=pq.top();
            int cost=cur[0], from=cur[1], to=cur[2];
            pq.pop();

            if (find(from)!=find(to))
            {
                Union(from, to);
                ret+=cost;
            }
        }
        return ret;
    }
    int find(int p)
    {
        if (parents[p]!=p) parents[p]=find(parents[p]);
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
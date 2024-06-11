class Solution {
    vector<int>parents;
    int count;
public:
    bool validTree(int n, vector<vector<int>> &edges) {
        for (int i=0; i<n; i++)
            parents.push_back(i);
        count=n;

        for (auto &edge : edges)
        {
            if (find(edge[0])==find(edge[1])) return false;

            Union(edge[0], edge[1]);
        }
        return count==1;
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
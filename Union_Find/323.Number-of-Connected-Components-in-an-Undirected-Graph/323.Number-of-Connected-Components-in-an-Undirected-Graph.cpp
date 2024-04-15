class Solution {
    vector<int>parents;
    int count;
public:
    int countComponents(int n, vector<vector<int>> &edges) {
        parents.resize(n);
        for (int i=0; i<n; i++)
            parents[i]=i;
        count=n;

        for (auto &edge : edges)
            Union(edge[0], edge[1]);
        return count;
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
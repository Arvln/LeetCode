class Solution {
    vector<int>parents;
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        for (int i=0; i<n; i++)
            parents.push_back(i);
        for (auto &edge : edges)
            Union(edge[0], edge[1]);
        return find(source)==find(destination);
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

        if(rootP==rootQ) return;
        parents[rootP]=rootQ;
    }
};
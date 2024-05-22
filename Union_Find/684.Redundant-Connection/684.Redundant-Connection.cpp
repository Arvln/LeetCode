class Solution {
    vector<int>parents;
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        for (int i=0; i<=n; i++)
            parents.push_back(i);
        
        for (auto edge : edges)
        {
            if (find(edge[0])==find(edge[1])) return edge;
            else Union(edge[0], edge[1]);
        }
        return {};
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
    }
};
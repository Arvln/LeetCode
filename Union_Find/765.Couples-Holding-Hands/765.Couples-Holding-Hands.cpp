class Solution {
    vector<int>parents;
public:
    int minSwapsCouples(vector<int>& row) {
        int n=row.size();
        parents=vector<int>(n);
        for (int i=0; i<n; i+=2)
        {
            parents[i]=i;
            parents[i+1]=i;
        }
        for (int i=0; i<n; i+=2)
            Union(row[i], row[i+1]);
        
        unordered_map<int, int>groups;
        for (int id : parents)
            groups[find(id)]++;
        int ret=0;
        for (auto &group : groups)
            ret+=group.second/2-1;
        return ret;
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
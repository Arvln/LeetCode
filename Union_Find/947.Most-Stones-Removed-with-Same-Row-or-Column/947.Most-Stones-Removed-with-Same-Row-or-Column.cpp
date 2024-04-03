class Solution {
    vector<int>parents;
    int count;
    unordered_map<int, vector<int>>rows; // row->ids
    unordered_map<int, vector<int>>cols; // col->ids
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        parents=vector<int>(n);
        for (int i=0; i<n; i++)
        {
            parents[i]=i;
            int x=stones[i][0], y=stones[i][1];
            rows[x].push_back(i);
            cols[y].push_back(i);
        }
        count=n;

        for (auto &row : rows)
        {
            int first=row.second[0];

            for (int i=1; i<row.second.size(); i++)
                Union(first, row.second[i]);
        }
        for (auto &col : cols)
        {
            int first=col.second[0];

            for (int i=1; i<col.second.size(); i++)
                Union(first, col.second[i]);
        }
        return n-count;
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
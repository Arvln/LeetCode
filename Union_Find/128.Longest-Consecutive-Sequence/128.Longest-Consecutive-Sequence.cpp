class Solution {
    unordered_map<int, int>parents; // id->root
public:
    int longestConsecutive(vector<int>& nums) {
        for (int num : nums)
            parents[num]=num;
        for (int num : nums)
        {
            if (parents.find(num-1)!=parents.end()) Union(num, num-1);
            if (parents.find(num+1)!=parents.end()) Union(num, num+1);
        }
        
        unordered_map<int, int>groups; // root->count
        for (auto &parent : parents)
            groups[find(parent.first)]++;
        int ret=0;
        for (auto &group : groups)
            ret=max(ret, group.second);
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
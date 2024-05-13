class Solution {
    unordered_map<char, char>parents;
public:
    bool equationsPossible(vector<string>& equations) {
        for (char c='a'; c<='z'; c++)
            parents[c]=c;
        for (string &equation : equations)
            if (equation[1]=='=')
            {
                char a=equation[0], b=equation[3];
                Union(a, b);
            }
        for (string &equation : equations)
            if (equation[1]=='!')
            {
                char a=equation[0], b=equation[3];
                if (find(a)==find(b)) return false;
            }
        return true;
    }
    char find(char p)
    {
        if (p!=parents[p]) parents[p]=find(parents[p]);
        return parents[p];
    }
    void Union(char p, char q)
    {
        char rootP=find(p);
        char rootQ=find(q);

        if (rootP==rootQ) return;
        parents[rootP]=rootQ;
    }
};
class Solution {
    unordered_map<string, string>parents; // email->root
    unordered_map<string, string>emailToName; // email->name
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        for (auto account : accounts)
        {
            string name=account[0];
            for (int i=1; i<account.size(); i++)
            {
                if (parents.find(account[i])==parents.end())
                    parents[account[i]]=account[i];
                
                Union(account[i], account[1]);
                emailToName[account[i]]=name;
            }
        }

        unordered_map<string, vector<string>>Map; // root->results
        for (auto &parent : parents)
        {
            string root=find(parent.first);

            if (Map[root].empty()) Map[root].push_back(emailToName[root]);
            Map[root].push_back(parent.first);
        }
        
        vector<vector<string>>rets;
        for (auto &root : Map)
        {
            sort(root.second.begin()+1, root.second.end());
            rets.push_back(root.second);
        }
        return rets;
    }
    string find(string p)
    {
        if (p!=parents[p]) parents[p]=find(parents[p]);
        return parents[p];
    }
    void Union(string p, string q)
    {
        string rootP=find(p);
        string rootQ=find(q);

        if (rootP==rootQ) return;
        parents[rootP]=rootQ;
    }
};
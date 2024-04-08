class Solution {
public:
    string alienOrder(vector<string> &words) {
        unordered_map<char, unordered_set<char>>order;
        map<char, int>inDegree;
        for (string word : words)
            for (char c : word) 
              inDegree[c]=-1;

        for (int i=1; i<words.size(); i++)
        {
            string a=words[i-1], b=words[i];

            if (a.size()>b.size()&&a.substr(0, b.size())==b) return "";

            for (int j=0; j<min(a.size(), b.size()); j++)
            {
                if (a[j]==b[j]) continue;
                else if (order[a[j]].find(b[j])==order[a[j]].end())
                {
                    order[a[j]].insert(b[j]);
                    if (inDegree[a[j]]==-1) inDegree[a[j]]=0;
                    if (inDegree[b[j]]==-1) inDegree[b[j]]=0;
                    inDegree[b[j]]++;
                }
                break;
            }
        }

        for (auto &c : inDegree)
            if (c.second==1) break;
            else inDegree[c.first]=0;

        queue<char>q;
        for (auto &c : inDegree)
            if (c.second==0) q.push(c.first);
        string ret;
        while (!q.empty())
        {
            char cur=q.front();
            q.pop();
            ret.push_back(cur);

            for (auto &next : order[cur])
            {
                inDegree[next]--;
                if (inDegree[next]==0) q.push(next);
            }
        }
        for (auto &c : inDegree)
            if (inDegree[c.first]==-1) ret.push_back(c.first);

        if (ret.size()==inDegree.size()) return ret;
        else return "";
    }
};
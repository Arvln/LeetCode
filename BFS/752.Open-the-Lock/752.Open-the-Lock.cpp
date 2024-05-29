class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>Set(deadends.begin(), deadends.end());
        if (Set.find("0000")!=Set.end()) return -1;

        queue<string>q;
        unordered_set<string>visited;
        q.push("0000");
        visited.insert("0000");
        
        int ret=0;
        while (!q.empty())
        {
            for (int size=q.size(); size>0; size--)
            {
                string cur=q.front();
                q.pop();

                if (cur==target) return ret;

                for (string next : nexts(cur))
                {
                    if (Set.find(next)!=Set.end()) continue;
                    else if (visited.find(next)!=visited.end()) continue;

                    q.push(next);
                    visited.insert(next);
                }
            }
            ret++;
        }
        return -1;
    }
    char up(char num)
    {
        if (num=='9') return '0';
        else return num+1;
    }
    char down(char num)
    {
        if (num=='0') return '9';
        else return num-1;
    }
    vector<string> nexts(string &s)
    {
        vector<string>rets;
        for (int i=0; i<s.size(); i++)
        {
            char c=s[i];
            s[i]=up(c);
            rets.push_back(s);
            s[i]=down(c);
            rets.push_back(s);
            s[i]=c;
        }
        return rets;
    }
};
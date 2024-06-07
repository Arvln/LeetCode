class Solution {
    class Node {
    public:
        Node *next[26];
        bool isEnd;
    };
    Node *root;
    vector<string>ret;
    string path;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        root=new Node();
        for (string &word : wordDict)
        {
            Node *cur=root;
            for (char c : word)
            {
                if (cur->next[c-'a']==NULL) cur->next[c-'a']=new Node();
                cur=cur->next[c-'a'];
            }
            cur->isEnd=true;
        }
        dfs(s, 0);
        return ret;
    }
    void dfs(string &s, int cur)
    {
        if (cur==s.size())
        {
            ret.push_back(path);
            return;
        }

        Node *temp=root;
        for (int i=cur; i<s.size()&&temp!=NULL; i++)
        {
            temp=temp->next[s[i]-'a'];
            if (temp!=NULL&&temp->isEnd)
            {
                string curPath=path;
                path+=s.substr(cur, i-cur+1);
                if (i+1<s.size()) path.push_back(' ');
                dfs(s, i+1);
                path=curPath;
            }
        }
    }
};
class Solution {
    class Node {
    public:
        int count;
        Node *next[26];
    };
    Node *root;
    string ret;
public:
    string longestCommonPrefix(vector<string>& strs) {
        root=new Node();
        for (string &s : strs)
        {
            Node *cur=root;
            for (char &c : s)
            {
                if (cur->next[c-'a']==NULL) cur->next[c-'a']=new Node();
                cur=cur->next[c-'a'];
                cur->count++;
            }
        }
        dfs(root, strs.size());
        delete root;
        return ret;
    }
    void dfs(Node *node, int len)
    {
        for (char c='a'; c<='z'; c++)
        {
            Node *next=node->next[c-'a'];
            if (next==NULL||next->count<len) continue;
            ret.push_back(c);
            dfs(next, len);
        }
    }
};
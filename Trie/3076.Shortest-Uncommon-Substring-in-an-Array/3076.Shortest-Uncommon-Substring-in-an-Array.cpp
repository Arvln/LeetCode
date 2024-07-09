class Solution {
    class Node {
    public:
        Node *next[26];
        int count;

        void insert(string &s, int start)
        {
            Node *node=this;
            for (int i=start; i<s.size(); i++)
            {
                if (node->next[s[i]-'a']==NULL) node->next[s[i]-'a']=new Node();
                node=node->next[s[i]-'a'];
                node->count++;
            }
        }
    };
    Node *root;
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        root=new Node();
        for (string &s : arr)
            for (int i=0; i<s.size(); i++)
                root->insert(s, i);
        
        vector<string>ret;
        for (string &s : arr)
        {
            Node *cur=new Node();
            for (int i=0; i<s.size(); i++)
                cur->insert(s, i);
            
            string subStr;
            for (int i=0; i<s.size(); i++)
            {
                string str=findMatch(cur, s, i);
                
                if (str.empty()) continue;
                else if (subStr.empty()) subStr=str;
                else if (str.size()>subStr.size()) continue;
                else if (str.size()<subStr.size()) subStr=str;
                else if (subStr>str) subStr=str;
            }
            ret.push_back(subStr);
            delete cur;
        }
        delete root;
        return ret;
    }
    string findMatch(Node *node, string &s, int start)
    {
        Node *node0=root, *node1=node;
        string str;
        for (int i=start; i<s.size(); i++)
        {
            str.push_back(s[i]);
            node0=node0->next[s[i]-'a'];
            node1=node1->next[s[i]-'a'];

            if (node0->count==node1->count) return str;
        }
        return "";
    }
};
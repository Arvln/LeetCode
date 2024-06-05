class Trie {
    class Node {
    public:
        Node *next[26];
        bool isEnd;
    };
    Node *root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node *cur=root;
        for (char c : word)
        {
            if (cur->next[c-'a']==NULL) cur->next[c-'a']=new Node();
            cur=cur->next[c-'a'];
        }
        cur->isEnd=true;
    }

    Node* fetchNode(string &s)
    {
        Node *cur=root;
        for (int i=0; i<s.size()&&cur!=NULL; i++)
            cur=cur->next[s[i]-'a'];
        return cur;
    }
    
    bool search(string word) {
        Node *cur=fetchNode(word);
        return cur!=NULL&&cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        return fetchNode(prefix)!=NULL;
    }
};